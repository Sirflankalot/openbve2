#include "parsers/ini.hpp"
#include "util/parsing.hpp"
#include <algorithm>

namespace bve::parsers::ini {
	ParsedINIObject parse(const std::string& file_string) {
		auto begin = file_string.begin();
		auto const end = file_string.end();

		ParsedINIObject pio;
		pio.emplace_back();

		std::size_t line_number = 1;

		while (begin != end) {
			auto const next_newline = std::find(begin, end, '\n');

			auto line = std::string(begin, next_newline);
			util::parsers::strip_text(line);

			if (!line.empty()) {
				// parse section header
				if (line[0] == '[') {
					auto const end_section_header = std::find(line.begin() + 1, line.end(), ']');
					INISection sec;
					sec.name = std::string(line.begin() + 1, end_section_header);
					sec.line = line_number;
					pio.emplace_back(sec);
				}
				// parse other property declarations
				else {
					auto const equals_iter = std::find(line.begin(), line.end(), '=');
					// Non equals declaration
					if (equals_iter == line.end()) {
						pio.back().values.emplace_back(Value{line, line_number});
					}
					// Equals declaration
					else {
						KeyValuePair key_value;

						key_value.key = std::string(line.begin(), equals_iter);
						key_value.value = std::string(equals_iter + 1, line.end());
						key_value.line = line_number;

						util::parsers::strip_text(key_value.key);
						util::parsers::strip_text(key_value.value);

						pio.back().key_value_pairs.emplace_back(std::move(key_value));
					}
				}
			}

			begin = next_newline == end ? next_newline : next_newline + 1;
			line_number += 1;
		}

		return pio;
	}
} // namespace bve::parsers::ini
