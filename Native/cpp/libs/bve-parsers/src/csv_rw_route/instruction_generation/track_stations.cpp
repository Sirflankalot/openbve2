#include "instruction_generator.hpp"
#include <gsl/gsl_util>

using namespace std::string_literals;

namespace bve::parsers::csv_rw_route::instruction_generation {
	// ReSharper disable once CyclomaticComplexity
	Instruction create_instruction_track_sta(const line_splitting::InstructionInfo& inst) {
		args_at_least(inst, 1, "Track.Sta");

		instructions::track::Sta s;

		switch (inst.args.size()) {
			default:
			case 12:
				s.timetable_index = gsl::narrow<std::size_t>(util::parsers::parse_loose_integer(inst.args[11], 0));
				[[fallthrough]];
			case 11:
				s.departure_sound = inst.args[10];
				[[fallthrough]];
			case 10:
				s.passenger_ratio = util::parsers::parse_loose_float(inst.args[9], 100);
				[[fallthrough]];
			case 9:
				s.stop_duration = util::parsers::parse_loose_float(inst.args[8], 15);
				[[fallthrough]];
			case 8:
				s.arrival_sound = inst.args[7];
				[[fallthrough]];
			case 7:
				// System
				{
					auto const arg_val = util::parsers::lower_copy(inst.args[6]);
					s.system = arg_val == "atc" || arg_val == "1";
				}
				[[fallthrough]];
			case 6:
				// Forced Red Signal
				{
					auto const val = util::parsers::parse_loose_integer(inst.args[5], 0);
					s.force_red = val == 1;
				}
				[[fallthrough]];
			case 5:
				// Doors
				{
					auto& arg_val = inst.args[4];
					if (arg_val.empty()) {
						s.doors = instructions::track::Sta::Doors::none;
					}
					else {
						switch (arg_val[0]) {
							case 'l':
							case 'L':
								s.doors = instructions::track::Sta::Doors::left;
								break;
							case 'n':
							case 'N':
								s.doors = instructions::track::Sta::Doors::none;
								break;
							case 'r':
							case 'R':
								s.doors = instructions::track::Sta::Doors::right;
								break;
							case 'b':
							case 'B':
								s.doors = instructions::track::Sta::Doors::both;
								break;
							default: {
								auto const val = util::parsers::parse_loose_integer(arg_val, 0);
								switch (val) {
									case -1:
										s.doors = instructions::track::Sta::Doors::left;
										break;
									default:
									case 0:
										s.doors = instructions::track::Sta::Doors::none;
										break;
									case 1:
										s.doors = instructions::track::Sta::Doors::right;
										break;
								}
								break;
							}
						}
					}
				}
				[[fallthrough]];
			case 4:
				// Pass Alarm
				{
					auto const val = util::parsers::parse_loose_integer(inst.args[3], 0);
					s.pass_alarm = val == 1;
				}
				[[fallthrough]];
			case 3:
				// Departure Time
				{
					auto& arr_arg = inst.args[2];
					if (arr_arg.empty()) {
						s.departure_tag = instructions::track::Sta::DepartureTime::any_time;
					}
					else {
						switch (arr_arg[0]) {
							case 't':
							case 'T':
							case '=':
								if (arr_arg.size() >= 3 && arr_arg[1] == ':') {
									s.departure = util::parsers::parse_time(arr_arg.substr(2));
									s.departure_tag = instructions::track::Sta::DepartureTime::terminal_time;
								}
								else {
									s.departure_tag = instructions::track::Sta::DepartureTime::terminal;
								}
								break;
							case 'c':
							case 'C':
								if (arr_arg.size() >= 3 && arr_arg[1] == ':') {
									s.departure = util::parsers::parse_time(arr_arg.substr(2));
									s.departure_tag = instructions::track::Sta::DepartureTime::change_ends;
								}
								else {
									s.departure_tag = instructions::track::Sta::DepartureTime::change_ends_time;
								}
								break;
							default:
								s.departure = util::parsers::parse_time(arr_arg);
								break;
						}
					}
				}
				[[fallthrough]];
			case 2:
				// Arrival time
				{
					auto& arr_arg = inst.args[1];
					if (arr_arg.empty()) {
						s.arrival_tag = instructions::track::Sta::ArrivalTime::any_time;
					}
					else {
						switch (arr_arg[0]) {
							case 'p':
							case 'P':
							case 'l':
							case 'L':
								s.arrival_tag = instructions::track::Sta::ArrivalTime::all_pass;
								break;
							case 'b':
							case 'B':
								s.arrival_tag = instructions::track::Sta::ArrivalTime::player_pass;
								break;
							case 's':
							case 'S':
								s.arrival_tag = instructions::track::Sta::ArrivalTime::player_stop;

								if (arr_arg.size() >= 3 && arr_arg[1] == ':') {
									s.arrival = util::parsers::parse_time(arr_arg.substr(2));
								}
								break;
							default:
								s.arrival_tag = instructions::track::Sta::ArrivalTime::time;
								s.arrival = util::parsers::parse_time(arr_arg);
						}
					}
				}
				[[fallthrough]];
			case 1:
				s.name = inst.args[0];
				[[fallthrough]];
			case 0:
				break;
		}

		return s;
	}

	Instruction create_instruction_track_station(const line_splitting::InstructionInfo& inst) {
		args_at_least(inst, 1, "Track.Station");

		line_splitting::InstructionInfo ii;
		ii.name = inst.name;
		ii.args.resize(12);
		ii.args[0] = !inst.args.empty() ? inst.args[0] : ""s;     // Name
		ii.args[1] = inst.args.size() >= 2 ? inst.args[1] : ""s;  // ArrivalTime
		ii.args[2] = inst.args.size() >= 3 ? inst.args[2] : ""s;  // DepartureTime
		ii.args[3] = "0"s;                                        // Pass Alarm
		ii.args[4] = "b"s;                                        // Doors
		ii.args[5] = inst.args.size() >= 4 ? inst.args[3] : "0"s; // ForcedRedSignal
		ii.args[6] = inst.args.size() >= 5 ? inst.args[4] : "0"s; // System
		ii.args[7] = ""s;                                         // Arrival Sound
		ii.args[8] = "15"s;                                       // Stop Duration
		ii.args[9] = "100"s;                                      // PassengerRatio
		ii.args[10] = inst.args.size() >= 6 ? inst.args[5] : ""s; // DepartureSound
		ii.args[11] = "0"s;                                       // Timetable Index

		return create_instruction_track_sta(ii);
	}

	Instruction create_instruction_track_station_xml(InstInfo const& inst) {
		args_at_least(inst, 1, "Track.StationXML");

		instructions::track::StationXml xml;

		xml.filename = inst.args[0];

		return xml;
	}

	Instruction create_instruction_track_stop(const line_splitting::InstructionInfo& inst) {
		instructions::track::Stop s;

		switch (inst.args.size()) {
			default:
			case 4:
				s.cars = gsl::narrow<std::size_t>(util::parsers::parse_loose_integer(inst.args[3], 0));
				[[fallthrough]];
			case 3:
				s.forwards_tolerance = util::parsers::parse_loose_float(inst.args[2], 5);
				[[fallthrough]];
			case 2:
				s.backwards_tolerance = util::parsers::parse_loose_float(inst.args[1], 5);
				[[fallthrough]];
			case 1: {
				auto const direction_num = util::parsers::parse_loose_integer(inst.args[0], 0);

				switch (direction_num) {
					case -1:
						s.stop_post = instructions::track::Stop::StopPost::left;
						break;
					default:
					case 0:
						s.stop_post = instructions::track::Stop::StopPost::none;
						break;
					case 1:
						s.stop_post = instructions::track::Stop::StopPost::right;
						break;
				}
			}
				[[fallthrough]];
			case 0:
				break;
		}

		return s;
	}

	Instruction create_instruction_track_form(const line_splitting::InstructionInfo& inst) {
		args_at_least(inst, 2, "Track.Form");

		instructions::track::Form f;

		switch (inst.args.size()) {
			default:
			case 4:
				f.form_structure_index = gsl::narrow<std::size_t>(util::parsers::parse_loose_integer(inst.args[3], 0));
				[[fallthrough]];
			case 3:
				f.roof_structure_index = gsl::narrow<std::size_t>(util::parsers::parse_loose_integer(inst.args[2], 0));
				[[fallthrough]];
			case 2:
				if (!inst.args[1].empty()) {
					switch (inst.args[1][0]) {
						case 'l':
						case 'L':
							f.placement = instructions::track::Form::Placement::left;
							break;
						case 'r':
						case 'R':
							f.placement = instructions::track::Form::Placement::right;
							break;
						default:
							f.rail_index_2 = gsl::narrow_cast<std::size_t>(util::parsers::parse_loose_integer(inst.args[1], 0));
							f.placement = instructions::track::Form::Placement::rail_index;
							break;
					}
				}
				else {
					f.rail_index_2 = 0;
					f.placement = instructions::track::Form::Placement::rail_index;
				}
				[[fallthrough]];
			case 1:
				f.rail_index_1 = gsl::narrow_cast<std::size_t>(util::parsers::parse_loose_integer(inst.args[0]));
				[[fallthrough]];
			case 0:
				break;
		}

		// ReSharper disable once CppSomeObjectMembersMightNotBeInitialized
		return f;
	}
} // namespace bve::parsers::csv_rw_route::instruction_generation
