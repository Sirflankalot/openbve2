#include "function_scripts.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>

namespace bve::parsers::function_scripts {
	namespace {
		bool is_special_symbol(char const c) {
			switch (c) {
				case '+':
				case '-':
				case '*':
				case '/':
				case '=':
				case '!':
				case '<':
				case '>':
				case '&':
				case '|':
				case '^':
				case '(':
				case ')':
				case '[':
				case ']':
				case ',':
					return true;
				default:
					return false;
			}
		}

		bool is_number(char const c) {
			return '0' <= c && c <= '9';
		}

		bool is_start_of_number(char const c) {
			return is_number(c) || c == '.';
		}

		bool is_part_of_variable(char const c) {
			return !is_special_symbol(c) && std::isspace(c) == 0;
		}
	} // namespace

	// ReSharper disable once CyclomaticComplexity
	lexer_token_list lex(const std::string& text, errors::errors_t& errors) {
		lexer_token_list ltl;

		for (std::size_t i = 0; i < text.size(); ++i) {
			lexer_token lt;

			auto const has_another_character = i + 1 < text.size();

			// parsing number
			if (is_start_of_number(text[i])) {
				auto has_dot = false;

				// find if the number has a . in it
				std::find_if(text.begin() + i, text.end(), [&has_dot](char const c) {
					if (c == '.') {
						has_dot = true;
						return true;
					}
					return !is_number(c);
				});

				auto const has_another_number_character =
				    has_another_character && (is_number(text[i + 1]) || text[i + 1] == '.');

				// parsing float
				if (has_dot && has_another_number_character) {
					// NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
					auto const start_ptr = text.c_str() + i;
					char* str_end = nullptr;
					auto const f = std::strtof(start_ptr, &str_end);

					lt = lexer_types::floating{f};
					auto const chars_used = std::max<std::ptrdiff_t>(
					    0, std::distance<const char*>(
					           start_ptr,
					           // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
					           str_end - 1));
					i += chars_used;
				}
				// parsing int
				else if (!(has_dot && !has_another_number_character)) {
					// NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
					auto const start_ptr = text.c_str() + i;
					char* str_end = nullptr;
					auto const integer = std::strtoll(start_ptr, &str_end, 10);

					lt = lexer_types::integer{integer};
					// NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
					auto const chars_used = std::distance<const char*>(start_ptr, str_end - 1);
					i += chars_used;
				}
				// Raw dash/dot
				else if (has_dot) {
					lt = lexer_types::dot{};
				}
			}
			// parsing symbol
			else if (is_special_symbol(text[i])) {
				switch (text[i]) {
					case '+':
						lt = lexer_types::plus{};
						break;
					case '-':
						lt = lexer_types::minus{};
						break;
					case '*':
						lt = lexer_types::star{};
						break;
					case '/':
						lt = lexer_types::slash{};
						break;
					case '=':
						if (has_another_character && text[i + 1] == '=') {
							i += 1;
						}
						else {
							errors.emplace_back<errors::error_t>({0, R"("=" must be "==")"});
						}
						lt = lexer_types::double_eq{};
						break;
					case '!':
						if (has_another_character && text[i + 1] == '=') {
							lt = lexer_types::un_eq{};
							i += 1;
						}
						else {
							lt = lexer_types::bang{};
						}
						break;
					case '<':
						if (has_another_character && text[i + 1] == '=') {
							lt = lexer_types::less_eq{};
							i += 1;
						}
						else {
							lt = lexer_types::less{};
						}
						break;
					case '>':
						if (has_another_character && text[i + 1] == '=') {
							lt = lexer_types::greater_eq{};
							i += 1;
						}
						else {
							lt = lexer_types::greater{};
						}
						break;
					case '&':
						lt = lexer_types::ampersand{};
						break;
					case '|':
						lt = lexer_types::bar{};
						break;
					case '^':
						lt = lexer_types::carret{};
						break;
					case '(':
						lt = lexer_types::l_paren{};
						break;
					case ')':
						lt = lexer_types::r_paren{};
						break;
					case '[':
						lt = lexer_types::l_bracket{};
						break;
					case ']':
						lt = lexer_types::r_bracket{};
						break;
					case ',':
						lt = lexer_types::comma{};
						break;
					default:
						break;
				}
			}
			// parsing variable
			else if (std::isspace(text[i]) == 0) {
				// Find end of variable
				auto i2 = i;
				for (; i2 < text.size() && is_part_of_variable(text[i2]); ++i2) {
				}

				std::string var{text.begin() + i, text.begin() + i2};

				lt = lexer_types::variable{std::move(var)};

				if (has_another_character) {
					i2 -= 1;
				}
				i = i2;
			}
			else {
				continue;
			}

			ltl.emplace_back(std::move(lt));
		}

		return ltl;
	}
} // namespace bve::parsers::function_scripts