#include "csv.hpp"
#include "utils.hpp"
#include <algorithm>
#include <gsl/gsl_util>

namespace bve::parsers::csv {
	parsed_csv parse(const std::string& file, split_first_column sfc, char delim, char split_char) {
		// start with at least one row
		std::vector<std::vector<csv_token>> token_list{1, std::vector<csv_token>{}};

		auto begin = file.begin();
		auto const end = file.end();

		auto last_newline_iterator = begin;
		std::size_t current_line = 1;

		auto last_loop = false;
		auto newline = true;

		while (!last_loop) {
			// find next comma/newline
			auto const next_delim = std::find_if(begin, end, [&](char const c) {
				return (sfc == split_first_column::yes && newline ? c == split_char : false)
				       || c == delim || c == '\n';
			});

			newline = false;

			auto s = std::string{begin, next_delim};

			util::strip_text(s);

			csv_token token{std::move(s), current_line, current_line,
			                gsl::narrow<std::size_t>(std::distance(last_newline_iterator, begin)),
			                gsl::narrow<std::size_t>(
			                    std::distance(last_newline_iterator, next_delim))};

			token_list.back().emplace_back(std::move(token));

			if (next_delim != end) {
				if (*next_delim == '\n') {
					newline = true;
					last_newline_iterator = next_delim + 1;
					current_line++;
					token_list.emplace_back();
				}
			}
			if (last_loop) {
				break;
			}

			if (next_delim != end) {
				begin = next_delim + 1;
			}
			else {
				last_loop = true;
			}
		}

		return token_list;
	}
} // namespace bve::parsers::csv
