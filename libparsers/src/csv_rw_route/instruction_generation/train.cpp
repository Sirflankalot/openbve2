#include "instruction_generator.hpp"

namespace parsers {
namespace csv_rw_route {
	namespace instruction_generation {
		instruction create_instruction_train_folder(const line_splitting::instruction_info& inst) {
			return create_single_string_instruction<instructions::train::Folder>(inst,
			                                                                     "Train.Folder");
		}

		instruction create_instruction_train_run(const line_splitting::instruction_info& inst) {
			indices_at_least(inst, 1, "Train.Run");
			args_at_least(inst, 1, "Train.Run");

			instructions::train::Rail r;

			r.rail_type_index = std::size_t(util::parse_loose_integer(inst.indices[0]));
			r.run_sound_index = std::size_t(util::parse_loose_integer(inst.args[0]));

			return r;
		}

		instruction create_instruction_train_flange(const line_splitting::instruction_info& inst) {
			indices_at_least(inst, 1, "Train.Flange");
			args_at_least(inst, 1, "Train.Flange");

			instructions::train::Flange f;

			f.rail_type_index = std::size_t(util::parse_loose_integer(inst.indices[0]));
			f.flange_sound_index = std::size_t(util::parse_loose_integer(inst.args[0]));

			return f;
		}

		instruction create_instruction_train_timetable(
		    const line_splitting::instruction_info& inst) {
			indices_at_least(inst, 1, "Train.Timetable");
			args_at_least(inst, 1, "Train.Timetable");

			instructions::train::Timetable tt;

			tt.timetable_index = std::size_t(util::parse_loose_integer(inst.indices[0]));
			tt.filename = inst.args[0];

			auto suffixes = util::split_text(inst.suffix, '.');

			if (suffixes.empty() || (suffixes[0] != "day" && suffixes[0] != "night")) {
				throw std::invalid_argument(
				    "A suffix of .Day or .Night is required for "
				    "Train.Timetable");
			}

			tt.day = suffixes[0] == "day";

			return tt;
		}

		instruction create_instruction_train_velocity(
		    const line_splitting::instruction_info& inst) {
			return create_single_float_instruction<instructions::train::Velocity>(inst,
			                                                                      "Train.Velocity",
			                                                                      0);
		}
	} // namespace instruction_generation
} // namespace csv_rw_route
} // namespace parsers