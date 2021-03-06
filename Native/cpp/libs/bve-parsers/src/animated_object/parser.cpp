#include "parsers/animated.hpp"
#include "parsers/function_scripts.hpp"
#include "parsers/ini.hpp"
#include "util/parsing.hpp"
#include <algorithm>
#include <gsl/string_span>
#include <iterator>
#include <map>
#include <sstream>
#include <util/gsl_string_span_iostream.hpp>

using namespace std::string_literals;

namespace bve::parsers::animated_object {
	namespace {
		//////////////////////
		// Helper functions //
		//////////////////////
		glm::vec2 parse_2_argument_list(ParsedAnimatedObject& pso,
		                                gsl::cstring_span<> const value_name,
		                                std::size_t const line_number,
		                                std::string const& list) {
			auto split_list = util::parsers::split_text(list, ',');

			if (split_list.size() != 2) {
				std::ostringstream oss;
				oss << value_name << " must take 2 arguments\n";
				add_error(pso.errors, line_number, oss.str());
			}

			glm::vec2 value{};

			switch (split_list.size()) {
				default:
				case 2:
					value.y = util::parsers::parse_loose_float(split_list[1]);
					[[fallthrough]];
				case 1:
					value.x = util::parsers::parse_loose_float(split_list[0]);
					[[fallthrough]];
				case 0:
					break;
			}

			return value;
		}

		glm::vec3 parse_3_argument_list(ParsedAnimatedObject& pso,
		                                gsl::cstring_span<> const value_name,
		                                std::size_t const line_number,
		                                std::string const& list) {
			auto split_list = util::parsers::split_text(list, ',');

			if (split_list.size() != 3) {
				std::ostringstream oss;
				oss << value_name << " must take 3 arguments\n";
				add_error(pso.errors, line_number, oss.str());
			}

			glm::vec3 value{};

			switch (split_list.size()) {
				default:
				case 3:
					value.z = util::parsers::parse_loose_float(split_list[2]);
					[[fallthrough]];
				case 2:
					value.y = util::parsers::parse_loose_float(split_list[1]);
					[[fallthrough]];
				case 1:
					value.x = util::parsers::parse_loose_float(split_list[0]);
					[[fallthrough]];
				case 0:
					break;
			}

			return value;
		}

		FunctionScript parse_function_script(ParsedAnimatedObject& pso, gsl::cstring_span<> const function, std::size_t line) {
			(void) pso;
			auto instructions = function_scripts::parse(to_string(function));
			std::for_each(instructions.errors.begin(), instructions.errors.end(), [&line](errors::Error& e) { e.line = line; });
			std::copy(instructions.errors.begin(), instructions.errors.end(), std::back_inserter(pso.errors));
			return instructions;
		}

		/////////////////////////////
		// Value parsing functions //
		/////////////////////////////

		void parse_position(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().position = parse_3_argument_list(pso, "Position", section.line, section.value);
		}

		void parse_states(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			auto states = util::parsers::split_text(section.value, ',');

			for (auto& state : states) {
				util::parsers::strip_text(state);
			}

			pso.subobjects.back().states = states;
		}

		void parse_state_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().state_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_translate_x_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().translate_x_direction = parse_3_argument_list(pso, "TranslateXDirection", section.line, section.value);
		}
		void parse_translate_y_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().translate_y_direction = parse_3_argument_list(pso, "TranslateYDirection", section.line, section.value);
		}
		void parse_translate_z_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().translate_z_direction = parse_3_argument_list(pso, "TranslateZDirection", section.line, section.value);
		}

		void parse_translate_x_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().translate_x_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_translate_y_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().translate_y_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_translate_z_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().translate_z_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_rotate_x_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().rotate_x_direction = parse_3_argument_list(pso, "RotateXDirection", section.line, section.value);
		}
		void parse_rotate_y_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().rotate_y_direction = parse_3_argument_list(pso, "RotateYDirection", section.line, section.value);
		}
		void parse_rotate_z_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().rotate_z_direction = parse_3_argument_list(pso, "RotateZDirection", section.line, section.value);
		}

		void parse_rotate_x_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().rotate_x_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_rotate_y_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().rotate_y_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_rotate_z_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().rotate_z_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_rotate_x_damping(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			auto const list = parse_2_argument_list(pso, "RotateXDamping", section.line, section.value);

			auto& damping = pso.subobjects.back().rotate_x_damping;
			damping.frequency = list.x;
			damping.ratio = list.y;
		}

		void parse_rotate_y_damping(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			auto const list = parse_2_argument_list(pso, "RotateYDamping", section.line, section.value);

			auto& damping = pso.subobjects.back().rotate_y_damping;
			damping.frequency = list.x;
			damping.ratio = list.y;
		}

		void parse_rotate_z_damping(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			auto const list = parse_2_argument_list(pso, "RotateZDamping", section.line, section.value);

			auto& damping = pso.subobjects.back().rotate_z_damping;
			damping.frequency = list.x;
			damping.ratio = list.y;
		}

		void parse_texture_shift_x_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().texture_shift_x_direction =
			    parse_2_argument_list(pso, "TextureShiftXDirection", section.line, section.value);
		}

		void parse_texture_shift_y_direction(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().texture_shift_y_direction =
			    parse_2_argument_list(pso, "TextureShiftYDirection", section.line, section.value);
		}

		void parse_texture_shift_x_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().texture_shift_x_function = parse_function_script(pso, section.value, section.line);
		}
		void parse_texture_shift_y_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().texture_shift_y_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_track_follower_function(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().track_follower_function = parse_function_script(pso, section.value, section.line);
		}

		void parse_texture_override(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			if (util::parsers::match_against_lower(section.value, "timetable")) {
				pso.subobjects.back().timetable_override = true;
			}
			else if (util::parsers::match_against_lower(section.value, "none")) {
				pso.subobjects.back().timetable_override = false;
			}
			else {
				std::ostringstream oss;
				oss << section.value << " is not a valid value for TextureOverride";
				add_error(pso.errors, section.line, oss);
			}
		}

		void parse_refresh_rate(ParsedAnimatedObject& pso, ini::KeyValuePair const& section) {
			pso.subobjects.back().refresh_rate = util::parsers::parse_loose_float(section.value);
		}

		std::map<std::string, void (*)(ParsedAnimatedObject&, ini::KeyValuePair const&)> function_mapping = {
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

		void parse_object_section(ParsedAnimatedObject& pso, ini::INISection const& section) {
			pso.subobjects.emplace_back();

			for (auto const& assignment : section.key_value_pairs) {
				auto const found_func = function_mapping.find(util::parsers::lower_copy(assignment.key));
				if (found_func == function_mapping.end()) {
					add_error(pso.errors, assignment.line, "Member " + assignment.key + " not found");
				}
				else {
					try {
						found_func->second(pso, assignment);
					}
					catch (const std::invalid_argument& e) {
						add_error(pso.errors, assignment.line, e.what());
					}
				}
			}
		}

		void parse_include_section(ParsedAnimatedObject& pso, ini::INISection const& section) {
			std::vector<std::string> files;
			auto position = glm::vec3(0);

			for (auto const& file : section.values) {
				files.emplace_back(file.value);
			}

			for (auto const& kvp : section.key_value_pairs) {
				if (util::parsers::match_against_lower(kvp.key, "position")) {
					auto const split = util::parsers::split_text(kvp.value, ',');

					if (split.size() != 3) {
						add_error(pso.errors, kvp.line, "position must have 3 arguments");
					}

					try {
						switch (split.size()) {
							default:
							case 3:
								position.z = util::parsers::parse_loose_float(split[2]);
								[[fallthrough]];
							case 2:
								position.y = util::parsers::parse_loose_float(split[1]);
								[[fallthrough]];
							case 1:
								position.x = util::parsers::parse_loose_float(split[0]);
								[[fallthrough]];
							case 0:
								break;
						}
					}
					catch (const std::invalid_argument& e) {
						add_error(pso.errors, kvp.line, e.what());
					}
				}
				else {
					add_error(pso.errors, kvp.line,
					          "No other key may be set besides position "
					          "inside an include section");
				}
			}

			for (auto const& file : files) {
				pso.includes.emplace_back(AnimatedInclude{file, position});
			}
		}
	} // namespace

	ParsedAnimatedObject parse(std::string const& file_string) {
		ParsedAnimatedObject pao;

		auto const ini = ini::parse(file_string);

		for (auto const& section : ini) {
			// "" section is before any named section
			if (section.name.empty()) {
				for (auto const& value : section.values) {
					add_error(pao.errors, value.line,
					          "Animated files must have all commands within "
					          "sections");
				}

				for (auto const& kvp : section.key_value_pairs) {
					add_error(pao.errors, kvp.line,
					          "Animated files must have all commands within "
					          "sections");
				}
			}

			// all includes to the file
			else if (util::parsers::match_against_lower(section.name, "include", false)) {
				parse_include_section(pao, section);
			}

			// add object
			else if (util::parsers::match_against_lower(section.name, "object", false)) {
				parse_object_section(pao, section);
			}
			else {
				add_error(pao.errors, section.line, R"(Animated files may only have "Include" and "Object" sections)");
			}
		}

		return pao;
	}
} // namespace bve::parsers::animated_object
