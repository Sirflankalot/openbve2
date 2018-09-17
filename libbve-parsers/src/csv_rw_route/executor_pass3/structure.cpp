#include "executor_pass3.hpp"
#include <sstream>

namespace bve::parsers::csv_rw_route {
	void pass3_executor::operator()(const instructions::structure::command& inst) {
		auto const add_and_warn = [&](auto& container, const char* command_name) {
			auto filename_iter = add_object_filename(inst.filename);

			auto insert_pair =
			    container.insert(std::make_pair(inst.structure_index, filename_iter));

			auto& iterator = insert_pair.first;
			auto& inserted = insert_pair.second;

			if (!inserted) {
				auto& previous_filename = *iterator->second;
				iterator->second = filename_iter;
				std::ostringstream err;
				err << command_name << " overwriting index #" << inst.structure_index
				    << ". Old Filename: \"" << previous_filename << "\". Current Filename: \""
				    << *filename_iter << "\".";

				add_error(errors_, get_filename(inst.file_index), inst.line, err);
			}
		};

		auto const add_and_warn_cycle = [&](auto& container, const char* command_name) {
			auto filename_iter = add_object_filename(inst.filename);

			auto insert_pair =
			    container.insert(std::make_pair(inst.structure_index, filename_iter));

			auto& iterator = insert_pair.first;
			auto& inserted = insert_pair.second;

			if (!inserted) {
				auto old_value = iterator->second;
				iterator->second = filename_iter;

				std::ostringstream err;

				err << command_name << " overwriting index number " << inst.structure_index
				    << ". Old Filename: \"" << *old_value << "\". Current Filename: \""
				    << *filename_iter << "\".";

				add_error(errors_, get_filename(inst.file_index), inst.line, err);
			}
		};

		switch (inst.command_type) {
			case instructions::structure::command::ground:
				add_and_warn_cycle(object_ground_mapping_, "Structure.Ground");
				break;
			case instructions::structure::command::rail:
				add_and_warn_cycle(object_rail_mapping_, "Structure.Rail");
				break;
			case instructions::structure::command::wall_l:
				add_and_warn(object_wall_l_mapping_, "Structure.WallL");
				break;
			case instructions::structure::command::wall_r:
				add_and_warn(object_wall_r_mapping_, "Structure.WallR");
				break;
			case instructions::structure::command::dike_l:
				add_and_warn(object_dike_l_mapping_, "Structure.DikeL");
				break;
			case instructions::structure::command::dike_r:
				add_and_warn(object_dike_r_mapping_, "Structure.DikeR");
				break;
			case instructions::structure::command::form_l:
				add_and_warn(object_form_l_mapping_, "Structure.FormL");
				break;
			case instructions::structure::command::form_r:
				add_and_warn(object_form_r_mapping_, "Structure.FormR");
				break;
			case instructions::structure::command::form_cl:
				add_and_warn(object_form_cl_mapping_, "Structure.FormCL");
				break;
			case instructions::structure::command::form_cr:
				add_and_warn(object_form_cr_mapping_, "Structure.FormCR");
				break;
			case instructions::structure::command::roof_l:
				add_and_warn(object_roof_l_mapping_, "Structure.RoofL");
				break;
			case instructions::structure::command::roof_r:
				add_and_warn(object_roof_r_mapping_, "Structure.RoofR");
				break;
			case instructions::structure::command::roof_cl:
				add_and_warn(object_roof_cl_mapping_, "Structure.RoofCL");
				break;
			case instructions::structure::command::roof_cr:
				add_and_warn(object_roof_cr_mapping_, "Structure.RoofCR");
				break;
			case instructions::structure::command::crack_l:
				add_and_warn(object_crack_l_mapping_, "Structure.CrackL");
				break;
			case instructions::structure::command::crack_r:
				add_and_warn(object_crack_r_mapping_, "Structure.CrackR");
				break;
			case instructions::structure::command::free_obj:
				add_and_warn(object_freeobj_mapping_, "Structure.Freeobj");
				break;
			case instructions::structure::command::beacon:
				add_and_warn(object_beacon_mapping_, "Structure.Beacon");
				break;
			default:
				break;
		}
	}

	void pass3_executor::operator()(const instructions::structure::pole& inst) {
		auto filename_iter = add_object_filename(inst.filename);

		auto value =
		    std::make_pair(std::make_pair(inst.additional_rails, inst.pole_structure_index),
		                   filename_iter);
		auto insert_pair = object_pole_mapping_.insert(value);

		auto& iterator = insert_pair.first;
		auto& inserted = insert_pair.second;

		if (!inserted) {
			auto& previous_filename = *iterator->second;
			iterator->second = filename_iter;
			std::ostringstream err;
			err << "Structure.Pole overwriting pair (" << inst.additional_rails << ", "
			    << inst.pole_structure_index << "). Old Pair: \"" << previous_filename
			    << "\". Current Filename: \"" << *filename_iter << "\".";

			add_error(errors_, get_filename(inst.file_index), inst.line, err);
		}
	}
} // namespace bve::parsers::csv_rw_route
