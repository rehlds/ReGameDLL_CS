package versioning

import groovy.transform.CompileStatic
import groovy.transform.TypeChecked
import org.eclipse.jgit.api.Git
import org.eclipse.jgit.lib.ObjectId
import org.eclipse.jgit.lib.Repository
import org.eclipse.jgit.revwalk.RevCommit
import org.eclipse.jgit.revwalk.RevWalk
import org.eclipse.jgit.storage.file.FileRepositoryBuilder
import org.joda.time.DateTime
import org.joda.time.DateTimeZone

@CompileStatic @TypeChecked
class GitVersioner {

	static GitInfo versionForDir(String dir) {
		versionForDir(new File(dir))
	}
	static int getCountCommit(Repository repo) {
		Iterable<RevCommit> commits = Git.wrap(repo).log().call()
		int count = 0;
		commits.each {
			count++;
		}

		return count;
	}
	static GitInfo versionForDir(File dir) {
		FileRepositoryBuilder builder = new FileRepositoryBuilder()
		Repository repo = builder.setWorkTree(dir)
			.findGitDir()
			.build()

		ObjectId head = repo.resolve('HEAD')
		if (!head) {
			return null
		}

		def commit = new RevWalk(repo).parseCommit(head)
		def branch = repo.getBranch()
		def commitDate = new DateTime(1000L * commit.commitTime, DateTimeZone.UTC)
		int commitCount = getCountCommit(repo);

		String tag = repo.tags.find { kv -> kv.value.objectId == commit.id }?.key

		return new GitInfo(
			lastCommitDate: commitDate,
			branch: branch,
			tag: tag,
			countCommit: commitCount
		)
	}
}
