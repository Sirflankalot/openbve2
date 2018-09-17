#include "executor_pass3/executor_pass3.hpp"
#include "csv_rw_route.hpp"
#include <parsers/errors.hpp>

namespace bve::parsers::csv_rw_route {
	void execute_instructions_pass3(parsed_route_data& rd,
	                                instruction_list& list,
	                                errors::multi_error_t& errors,
	                                const find_relative_file_func& get_abs_path) {
		pass3_executor p3_e(rd, errors, list.filenames, get_abs_path);

		for (auto& inst : list.instructions) {
			apply_visitor(p3_e, inst);
		}

		auto const largest_position =
		    apply_visitor([](auto& inst) -> float { return inst.absolute_position; },
		                  list.instructions.back());

		p3_e.finalize(largest_position);
	}
} // namespace bve::parsers::csv_rw_route
