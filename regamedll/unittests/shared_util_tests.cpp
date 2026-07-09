#include "precompiled.h"
#include "cppunitlite/TestHarness.h"

// Regression test for the SharedParse() global-buffer overflow.
// s_shared_token is char[1500]; SharedParse() must never emit a token that
// does not fit, regardless of the size of a single unquoted/quoted token in
// the input. On the unpatched code the oversized-token cases below smash the
// global buffer (crash / memory corruption) before the CHECK is even reached.
const int SHARED_TOKEN_SIZE = 1500; // must match char s_shared_token[1500]

TEST(RegularWordOverflow, SharedParse, 10)
{
	// One unquoted "word" of 5000 non-space characters (no quotes/specials).
	static char input[5001];
	Q_memset(input, 'A', sizeof(input) - 1);
	input[sizeof(input) - 1] = '\0';

	SharedParse(input);
	CHECK("oversized word must be truncated", Q_strlen(SharedGetToken()) < SHARED_TOKEN_SIZE);
}

TEST(QuotedStringOverflow, SharedParse, 10)
{
	// One quoted string of 5000 characters between the quotes.
	static char input[5003];
	input[0] = '\"';
	Q_memset(input + 1, 'B', 5000);
	input[5001] = '\"';
	input[5002] = '\0';

	SharedParse(input);
	CHECK("oversized quoted string must be truncated", Q_strlen(SharedGetToken()) < SHARED_TOKEN_SIZE);
}

TEST(NormalTokensStillWork, SharedParse, 10)
{
	// The fix must not change behavior for well-formed input.
	char input[] = "  primaryWeapon   \"hello world\"  , ";
	char *p = SharedParse(input);
	CHECK("plain word token", Q_strcmp(SharedGetToken(), "primaryWeapon") == 0);

	p = SharedParse(p);
	CHECK("quoted string token", Q_strcmp(SharedGetToken(), "hello world") == 0);

	p = SharedParse(p);
	CHECK("comma token", Q_strcmp(SharedGetToken(), ",") == 0);
}
