#include "utils.hpp"
#include <doctest.h>

using namespace std::string_literals;

TEST_SUITE_BEGIN("libparsers - util");

TEST_CASE("libparsers - util - match_against_lower") {
	CHECK_EQ(parsers::util::match_against_lower("hello"s, "hello"), true);
	CHECK_EQ(parsers::util::match_against_lower("HeLlo"s, "hello"), true);
	CHECK_EQ(parsers::util::match_against_lower("Hello"s, "hell"), true);
	CHECK_EQ(parsers::util::match_against_lower("Hell"s, "hello"), true);

	CHECK_EQ(parsers::util::match_against_lower("hel1o"s, "hello"), false);
	CHECK_EQ(parsers::util::match_against_lower("HeL1o"s, "hello"), false);
	CHECK_EQ(parsers::util::match_against_lower("Hel1o"s, "hell"), false);
	CHECK_EQ(parsers::util::match_against_lower("Hel1"s, "hello"), false);
}

TEST_SUITE_END();