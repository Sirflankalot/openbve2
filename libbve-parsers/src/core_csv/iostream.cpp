#include "csv.hpp"
#include <ostream>

namespace bve::parsers::csv {
	std::ostream& operator<<(std::ostream& os, const csv_token& rhs) {
		os << "(\"" << rhs.text << "\", " << rhs.line_begin << ", " << rhs.line_end << ", "
		   << rhs.char_begin << ", " << rhs.char_end << ')';
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const parsed_csv& rhs) {
		for (auto& row : rhs) {
			for (std::size_t i = 0; i < row.size(); ++i) {
				os << row[i];
				if (i != row.size() - 1) {
					os << ", ";
				}
			}
			os << '\n';
		}
		return os;
	}
} // namespace bve::parsers::csv