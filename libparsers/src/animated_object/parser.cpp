#include "function_scripts.hpp"
#include "ini.hpp"
#include "parsers/animated.hpp"
#include "utils.hpp"
#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

using namespace std::string_literals;

namespace parsers {
namespace animated_object {
	namespace {
		//////////////////////
		// Helper functions //
		//////////////////////
		static glm::vec2 parse_2_argument_list(parsed_animated_object& pso, const char* const value_name,
		                                       const std::size_t line_number, const std::string& list) {
			auto split_list = util::split_text(list, ',');

			if (split_list.size() != 2) {
				std::ostringstream oss;
				oss << value_name << " must take 2 arguments\n";
				pso.errors.emplace_back(errors::error_t{line_number, oss.str()});
			}

			glm::vec2 value;

			switch (split_list.size()) {
				default:
				case 2:
					value.y = util::parse_loose_float(split_list[1]);
				case 1:
					value.x = util::parse_loose_float(split_list[0]);
				case 0:
					break;
			}

			return value;
		}

		static glm::vec3 parse_3_argument_list(parsed_animated_object& pso, const char* const value_name,
		                                       const std::size_t line_number, const std::string& list) {
			auto split_list = util::split_text(list, ',');

			if (split_list.size() != 3) {
				std::ostringstream oss;
				oss << value_name << " must take 3 arguments\n";
				pso.errors.emplace_back(errors::error_t{line_number, oss.str()});
			}

			glm::vec3 value;

			switch (split_list.size()) {
				default:
				case 3:
					value.z = util::parse_loose_float(split_list[2]);
				case 2:
					value.y = util::parse_loose_float(split_list[1]);
				case 1:
					value.x = util::parse_loose_float(split_list[0]);
				case 0:
					break;
			}

			return value;
		}

		static function_script parse_function_script(parsed_animated_object& pso, const std::string& function,
		                                             std::size_t line) {
			(void) pso;
			auto instructions = function_scripts::parse(function);
			std::for_each(instructions.errors.begin(), instructions.errors.end(),
			              [&line](errors::error_t& e) { e.line = line; });
			std::copy(instructions.errors.begin(), instructions.errors.end(), std::back_inserter(pso.errors));
			return instructions;
		}

		/////////////////////////////
		// Value parsing functions //
		/////////////////////////////

		static void parse_position(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().position = parse_3_argument_list(pso, "Position", section.line, section.value);
		}

		static void parse_states(parsed_animated_object& pso, const ini::kvp_t& section) {
			auto states = util::split_text(section.value, ',');

			for (auto& state : states) {
				util::strip_text(state);
			}

			pso.subobjects.back().states = states;
		}

		static void parse_state_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().state_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_translate_x_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().translate_x_direction =
			    parse_3_argument_list(pso, "TranslateXDirection", section.line, section.value);
		}
		static void parse_translate_y_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().translate_y_direction =
			    parse_3_argument_list(pso, "TranslateYDirection", section.line, section.value);
		}
		static void parse_translate_z_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().translate_z_direction =
			    parse_3_argument_list(pso, "TranslateZDirection", section.line, section.value);
		}

		static void parse_translate_x_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().translate_x_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_translate_y_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().translate_y_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_translate_z_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().translate_z_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_rotate_x_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().rotate_x_direction =
			    parse_3_argument_list(pso, "RotateXDirection", section.line, section.value);
		}
		static void parse_rotate_y_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().rotate_y_direction =
			    parse_3_argument_list(pso, "RotateYDirection", section.line, section.value);
		}
		static void parse_rotate_z_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().rotate_z_direction =
			    parse_3_argument_list(pso, "RotateZDirection", section.line, section.value);
		}

		static void parse_rotate_x_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().rotate_x_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_rotate_y_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().rotate_y_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_rotate_z_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().rotate_z_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_rotate_x_damping(parsed_animated_object& pso, const ini::kvp_t& section) {
			auto list = parse_2_argument_list(pso, "RotateXDamping", section.line, section.value);

			auto& damping = pso.subobjects.back().rotate_x_damping;
			damping.frequency = list.x;
			damping.ratio = list.y;
		}

		static void parse_rotate_y_damping(parsed_animated_object& pso, const ini::kvp_t& section) {
			auto list = parse_2_argument_list(pso, "RotateYDamping", section.line, section.value);

			auto& damping = pso.subobjects.back().rotate_y_damping;
			damping.frequency = list.x;
			damping.ratio = list.y;
		}

		static void parse_rotate_z_damping(parsed_animated_object& pso, const ini::kvp_t& section) {
			auto list = parse_2_argument_list(pso, "RotateZDamping", section.line, section.value);

			auto& damping = pso.subobjects.back().rotate_z_damping;
			damping.frequency = list.x;
			damping.ratio = list.y;
		}

		static void parse_texture_shift_x_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().texture_shift_x_direction =
			    parse_2_argument_list(pso, "TextureShiftXDirection", section.line, section.value);
		}

		static void parse_texture_shift_y_direction(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().texture_shift_y_direction =
			    parse_2_argument_list(pso, "TextureShiftYDirection", section.line, section.value);
		}

		static void parse_texture_shift_x_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().texture_shift_x_function = parse_function_script(pso, section.value, section.line);
		}
		static void parse_texture_shift_y_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().texture_shift_y_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_track_follower_function(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().track_follower_function = parse_function_script(pso, section.value, section.line);
		}

		static void parse_texture_override(parsed_animated_object& pso, const ini::kvp_t& section) {
			if (util::match_text(section.value, "timetable")) {
				pso.subobjects.back().timetable_override = true;
			}
			else if (util::match_text(section.value, "none")) {
				pso.subobjects.back().timetable_override = false;
			}
			else {
				std::ostringstream oss;
				oss << section.value << " is not a valid value for TextureOverride";
				pso.errors.emplace_back(errors::error_t{section.line, oss.str()});
			}
		}

		static void parse_refresh_rate(parsed_animated_object& pso, const ini::kvp_t& section) {
			pso.subobjects.back().refresh_rate = util::parse_loose_float(section.value);
		}

		std::map<std::string, void (*)(parsed_animated_object&, const ini::kvp_t&)> function_mapping = {
		    {"position"s, &parse_position},
		    {"states"s, &parse_states},
		    {"statefunction"s, &parse_state_function},
		    {"translatexdirection"s, &parse_translate_x_direction},
		    {"translateydirection"s, &parse_translate_y_direction},
		    {"translatezdirection"s, &parse_translate_z_direction},
		    {"translatexfunction"s, &parse_translate_x_function},
		    {"translateyfunction"s, &parse_translate_y_function},
		    {"translatezfunction"s, &parse_translate_z_function},
		    {"rotatexdirection"s, &parse_rotate_x_direction},
		    {"rotateydirection"s, &parse_rotate_y_direction},
		    {"rotatezdirection"s, &parse_rotate_z_direction},
		    {"rotatexfunction"s, &parse_rotate_x_function},
		    {"rotateyfunction"s, &parse_rotate_y_function},
		    {"rotatezfunction"s, &parse_rotate_z_function},
		    {"rotatexdamping"s, &parse_rotate_x_damping},
		    {"rotateydamping"s, &parse_rotate_y_damping},
		    {"rotatezdamping"s, &parse_rotate_z_damping},
		    {"textureshiftxdirection"s, &parse_texture_shift_x_direction},
		    {"textureshiftydirection"s, &parse_texture_shift_y_direction},
		    {"textureshiftxfunction"s, &parse_texture_shift_x_function},
		    {"textureshiftyfunction"s, &parse_texture_shift_y_function},
		    {"trackfollowerfunction"s, &parse_track_follower_function},
		    {"textureoverride"s, &parse_texture_override},
		    {"refreshrate"s, &parse_refresh_rate},
		};
	} // namespace

	static void parse_object_section(parsed_animated_object& pso, const ini::ini_section_t& section) {
		pso.subobjects.emplace_back();

		for (auto& assignment : section.key_value_pairs) {
			auto found_func = function_mapping.find(util::lower(assignment.key));
			if (found_func == function_mapping.end()) {
				pso.errors.emplace_back(errors::error_t{assignment.line, "Member " + assignment.key + " not found"});
			}
			else {
				try {
					(found_func->second)(pso, assignment);
				}
				catch (const std::invalid_argument& e) {
					pso.errors.emplace_back(errors::error_t{assignment.line, e.what()});
				}
			}
		}
	}

	static void parse_include_section(parsed_animated_object& pso, const ini::ini_section_t& section) {
		std::vector<std::string> files;
		glm::vec3 position = glm::vec3(0);

		for (auto& file : section.values) {
			files.emplace_back(file.value);
		}

		for (auto& kvp : section.key_value_pairs) {
			if (util::match_text(kvp.key, "position")) {
				auto split = util::split_text(kvp.value, ',');

				if (split.size() != 3) {
					pso.errors.emplace_back(errors::error_t{kvp.line, "Postion must have 3 arguments"});
				}

				try {
					switch (split.size()) {
						default:
						case 3:
							position.z = util::parse_loose_float(split[2]);
							// fall through
						case 2:
							position.y = util::parse_loose_float(split[1]);
							// fall through
						case 1:
							position.x = util::parse_loose_float(split[0]);
							// fall through
						case 0:
							break;
					}
				}
				catch (const std::invalid_argument& e) {
					pso.errors.emplace_back(errors::error_t{kvp.line, e.what()});
				}
			}
			else {
				pso.errors.emplace_back(
				    errors::error_t{kvp.line, "No other key may be set besides position inside an include section"});
			}
		}

		for (auto& file : files) {
			pso.includes.emplace_back(animated_include{file, position});
		}
	}

	parsed_animated_object parse(const std::string& file) {
		parsed_animated_object pao;

		auto ini = ini::parse(file);

		for (auto& section : ini) {
			// "" section is before any named section
			if (section.name == "") {
				for (auto& value : section.values) {
					pao.errors.emplace_back(
					    errors::error_t{value.line, "Animated files must have all commands within sections"});
				}

				for (auto& kvp : section.key_value_pairs) {
					pao.errors.emplace_back(
					    errors::error_t{kvp.line, "Animated files must have all commands within sections"});
				}
			}

			// all includes to the file
			else if (util::match_text(section.name, "includes")) {
				parse_include_section(pao, section);
			}

			// add object
			else if (util::match_text(section.name, "object")) {
				parse_object_section(pao, section);
			}
			else {
				pao.errors.emplace_back(
				    errors::error_t{section.line, "Animated files may only have \"Include\" and \"Object\" sections"});
			}
		}

		return pao;
	}
} // namespace animated_object
} // namespace parsers