#pragma once

#include "core/datatypes.hpp"
#include "parsers/errors.hpp"
#include <functional>
#include <mapbox/variant.hpp>
#include <string>
#include <vector>

namespace parsers {
namespace csv_rw_route {
	struct preprocessed_line {
		std::string contents;
		std::size_t filename_index;
		std::size_t line;
		float offset;
	};

	struct preprocessed_lines {
		std::vector<preprocessed_line> lines;
		std::vector<std::string> filenames;
	};

	preprocessed_lines process_include_files(
	    const std::string& filename, openbve2::datatypes::rng& rng, errors::multi_error& errors,
	    const std::function<std::string(const std::string& base_file, const std::string& relative)>& get_abs_path);

	void preprocess_file(preprocessed_lines& lines, openbve2::datatypes::rng& rng, errors::multi_error& errors);

#include "csv_rw_route/instructions.hpp"

	using instruction = mapbox::util::variant<
	    // with statement
	    instructions::naked::with,
	    // options commands
	    instructions::options::UnitOfLength, instructions::options::UnitOfSpeed, instructions::options::BlockLength,
	    instructions::options::ObjectVisibility, instructions::options::SectionBehavior,
	    instructions::options::CantBehavior, instructions::options::Fog,
	    instructions::options::CompatibleTransparencyMode, instructions::options::EnableBveTsHacks,
	    // route commands
	    instructions::route::Comment, instructions::route::Image, instructions::route::Timetable,
	    instructions::route::Change, instructions::route::Guage, instructions::route::Signal,
	    instructions::route::RunInterval, instructions::route::AccelerationDueToGravity, instructions::route::Elevation,
	    instructions::route::Temperature, instructions::route::Pressure, instructions::route::DisplaySpeed,
	    instructions::route::LoadingScreen, instructions::route::StartTime, instructions::route::DynamicLight,
	    instructions::route::AmbiantLight, instructions::route::DirectionalLight, instructions::route::LightDirection,
	    // train commands
	    instructions::train::Folder, instructions::train::Rail, instructions::train::Flange,
	    instructions::train::Timetable, instructions::train::Velocity,
	    // structure commands
	    instructions::structure::Command, instructions::structure::Pole,
	    // texture commands
	    instructions::texture::Background_Load, instructions::texture::Background_X,
	    instructions::texture::Background_Aspect,
	    // cycle commands,
	    instructions::cycle::Ground, instructions::cycle::Rail,
	    // signal commands,
	    instructions::naked::signal_animated, instructions::naked::signal,
	    // track,
	    instructions::track::RailStart, instructions::track::Rail, instructions::track::RailType,
	    instructions::track::RailEnd, instructions::track::Adhesion, instructions::track::Pitch,
	    instructions::track::Curve, instructions::track::Turn, instructions::track::Height,
	    instructions::track::FreeObj, instructions::track::Wall, instructions::track::WallEnd,
	    instructions::track::Dike, instructions::track::DikeEnd, instructions::track::Pole,
	    instructions::track::PoleEnd, instructions::track::Crack, instructions::track::Ground, instructions::track::Sta,
	    instructions::track::Stop, instructions::track::Form, instructions::track::Limit, instructions::track::Section,
	    instructions::track::SigF, instructions::track::Signal, instructions::track::Transponder,
	    instructions::track::Pattern, instructions::track::Back, instructions::track::Fog,
	    instructions::track::Brightness, instructions::track::Marker, instructions::track::TextMarker,
	    instructions::track::PointOfInterest, instructions::track::PreTrain, instructions::track::Announce,
	    instructions::track::Doppler, instructions::track::Buffer>;
} // namespace csv_rw_route
} // namespace parsers