#include "function_scripts/parse_tree.hpp"
#include "tests.hpp"
#include <iostream>
#include <string>

using namespace std::string_literals;

void test_fs() {
	// value 2 3 + 4 + * 15 2 4 / / == cameraMode 2 < c d & ?
	// auto test_string = "if[value * -Plus[2, 3, 4] == 15 / 2 / 4, cameraMode <
	// 2, c & d]"s; speed delta * 2.7632 Mod 2.7632 / 3.14 2 2 power power 2 * *
	// value + auto test_string = "value + Mod[(speed * delta), 2.7632] / 2.7632
	// * Power[3.14, 2, 2] * 2"s;
	bve::parsers::errors::Errors e;
	auto const test_string = ".25 * Reciprocal[floor[plus[Time * 0.1, 23, 1, pluginstate[2 * mod[-time, 4] + 25]]]] * Power[2]"s;

	auto const output = bve::parsers::function_scripts::lex(test_string, e);

	std::cout << output;

	auto const tree = bve::parsers::function_scripts::create_tree(output, e);

	std::cout << tree;

	auto const instructions = bve::parsers::function_scripts::build_instructions(tree, e);

	std::cout << instructions;
}
