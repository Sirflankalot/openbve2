#include "executor_pass3.hpp"
#include <ostream>
#include <sstream>
#include <vector>

namespace bve::parsers::csv_rw_route {
	absl::optional<FilenameSetIterator> get_cycle_filename_index(
	    const std::unordered_map<std::size_t, std::vector<std::size_t>>& cycle_mapping,
	    const std::unordered_map<std::size_t, FilenameSetIterator>& object_mapping,
	    std::size_t const index,
	    std::size_t const position) {
		auto const cycle_iterator = cycle_mapping.find(index);
		if (cycle_iterator != cycle_mapping.end()) {
			auto const index_to_use = position / 25 % cycle_iterator->second.size();

			auto const to_use_iter = object_mapping.find(cycle_iterator->second[index_to_use]);

			if (to_use_iter == object_mapping.end()) {
				return absl::nullopt;
			}

			return to_use_iter->second;
		}

		auto const to_use_iter = object_mapping.find(index);

		if (to_use_iter == object_mapping.end()) {
			return absl::nullopt;
		}

		return to_use_iter->second;
	}

	void print_cycle_type(std::ostream& o, const CycleType& c) {
		o << "Cycle of: (";
		std::size_t i = 0;
		for (auto& item : c) {
			o << "#" << item;
			if (++i != c.size()) {
				o << ", ";
			}
			o << ")";
		}
	}

	void Pass3Executor::operator()(const instructions::cycle::Ground& inst) {
		std::vector<std::size_t> cycle;

		for (auto& ground_index : inst.input_indices) {
			cycle.emplace_back(ground_index);
		}

		auto insert_ret = cycle_ground_mapping_.insert({inst.cycle_structure_index, cycle});

		auto& iterator = insert_ret.first;
		auto& inserted = insert_ret.second;

		if (!inserted) {
			auto const old_value = iterator->second;
			iterator->second = cycle;

			std::ostringstream err;

			err << "Cycle.Ground overwriting #" << inst.cycle_structure_index << ". Old Filename: \"";
			print_cycle_type(err, old_value);
			err << "\". Current Filename: \"";
			print_cycle_type(err, cycle);
			err << "\".";

			add_error(errors_, getFilename(inst.file_index), inst.line, err);
		}
	}

	void Pass3Executor::operator()(const instructions::cycle::Rail& inst) {
		std::vector<std::size_t> cycle;

		for (auto& ground_index : inst.input_indices) {
			cycle.emplace_back(ground_index);
		}

		auto insert_ret = cycle_rail_mapping_.insert({inst.cycle_structure_index, cycle});

		auto& iterator = insert_ret.first;
		auto& inserted = insert_ret.second;

		if (!inserted) {
			auto const old_value = iterator->second;
			iterator->second = cycle;

			std::ostringstream err;

			err << "Cycle.Rail overwriting index #" << inst.cycle_structure_index << ". Old Filename: \"";
			print_cycle_type(err, old_value);
			err << "\". Current Filename: \"";
			print_cycle_type(err, cycle);
			err << "\".";

			add_error(errors_, getFilename(inst.file_index), inst.line, err);
		}
	}
} // namespace bve::parsers::csv_rw_route
