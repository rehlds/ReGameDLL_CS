package regamedll.testdemo

import groovy.util.slurpersupport.GPathResult
import org.apache.commons.io.IOUtils

import java.util.zip.ZipFile

class RegamedllTestParser {
    static final String REGAMEDLL_TEST_METAINFO_FILE = 'regamedll_test_metainfo.xml'

    static RegamedllTestInfo parseTestInfo(File testArchive) {
        def zf = new ZipFile(testArchive);
        try {
            def metaInfoEntry = zf.getEntry(REGAMEDLL_TEST_METAINFO_FILE)
            if (metaInfoEntry == null) {
                throw new RuntimeException("Unable to open ${REGAMEDLL_TEST_METAINFO_FILE} in ${testArchive.absolutePath}")
            }

            GPathResult metaInfo = null
            zf.getInputStream(metaInfoEntry).withStream { InputStream ins ->
                metaInfo = new XmlSlurper().parse(ins)
            }

            RegamedllTestInfo testInfo = new RegamedllTestInfo(
                    testName: metaInfo.name.text(),
                    hldsArgs: metaInfo.runArgs.arg.list().collect { it.text().trim() },
                    timeoutSeconds: metaInfo.timeout.text() as int
            )

            //validate testInfo
            if (!testInfo.testName) {
                throw new RuntimeException("Error parsing ${testArchive.absolutePath}: test name is not specified")
            }

            if (!testInfo.hldsArgs) {
                throw new RuntimeException("Error parsing ${testArchive.absolutePath}: run arguments are not specified")
            }

            if (testInfo.timeoutSeconds <= 0) {
                throw new RuntimeException("Error parsing ${testArchive.absolutePath}: bad timeout")
            }

            def testBinName = testInfo.testName + '.bin'
            def testBinEntry = zf.getEntry(testBinName)
            if (testBinEntry == null) {
                throw new RuntimeException("Error parsing ${testArchive.absolutePath}: test binary ${testBinName} not found inside archive")
            }

            testInfo.testBinFile = File.createTempFile(testBinName, 'regamedll')
            testInfo.testBinFile.deleteOnExit()
            zf.getInputStream(testBinEntry).withStream { InputStream ins ->
                testInfo.testBinFile.withOutputStream { OutputStream os ->
                    IOUtils.copy(ins, os)
                }
            }

            return testInfo
        } finally {
            try { zf.close() } catch (Exception ignored) { }
        }

    }
}
