#include "core/math.hpp"
#include <cassert>
#include <glm/geometric.hpp>
#define _USE_MATH_DEFINES
#include <cmath> // Also include overloads of std::*
#include <math.h>

float openbve2::math::radius_from_distances(float deltax, float deltay) {
	// https://math.stackexchange.com/questions/1088902/what-is-the-radius-of-a-circle-given-two-points-and-the-center-of-the-circle-is#comment2218658_1088926
	// gives the formula for this
	// X = y1 in the formula
	// Z = x1 in the formula
	// y0 and x0 are both zero, so they can be ommitted.

	auto& x1 = deltax;
	auto& y1 = deltay;

	auto angle = std::atan2(y1, x1);

	auto num = std::sqrt(y1 * y1 + x1 * x1) * std::sin(float(M_PI_2) - angle);
	auto denom = std::sin(float(M_PI) - 2 * (float(M_PI_2) - angle));

	auto radius = num / denom;

	return radius;
}

openbve2::math::evaulate_curve_t openbve2::math::evaluate_curve(glm::vec3 input_position, glm::vec3 input_direction,
                                                                float distance, float radius) {
	auto original_input_direction = input_direction;
	if (input_direction == glm::vec3(0)) {
		input_direction = glm::vec3(0, 0, 1);
		original_input_direction = input_direction;
	}
	else {
		input_direction = glm::normalize(input_direction);
	}

	if (radius == 0) {
		input_position += input_direction * distance;
		return {input_position, input_direction};
	}

	float vertical_movement = input_direction.y * distance;

	// non-vertical movement we are allowed
	float horizontal_movement = std::sqrt(distance * distance - vertical_movement * vertical_movement);

	bool flipped_radius = radius < 0;
	radius = std::abs(radius);

	// convert from game direction coordinates to 2d cartisian plane
	auto xy = glm::vec2(input_direction.z, -input_direction.x);

	// get angle of input
	float atan = std::atan2(xy.y, xy.x);
	if (xy.y < 0) {
		atan += float(M_PI * 2);
	}

	// flip the result of arctan so the angles are going clockwise, not counter
	float input_angle = float(M_PI * 2) - atan;

	// compute fraction of circle traveled
	float circumference = 2 * float(M_PI) * radius;
	float frac_traveled = horizontal_movement / circumference;

	// get angle traveled in radians
	float travel_angle = frac_traveled * float(M_PI * 2);

	// make sure the ending angle includes the starting angle
	travel_angle += input_angle;

	// get coordinates on a unit circle with its center at (0,0)
	// right part of the circle is 90deg
	// bottom is 180, etc
	// hence why we flipped x and y, as we mirrored it over y=x

	// the track is comming in at (0,0)
	// right on the coordinate plane is moving forward (+z in game world)
	// down on the coordinate plane is turning right (+x in the game world)
	float travel_x = std::sin(travel_angle);
	float travel_y = std::cos(travel_angle);

	// Get tangent at ending point
	auto radius_line = glm::vec2(travel_x, travel_y) - glm::vec2(0, 0);
	glm::vec2 tangent_line;
	if (flipped_radius) {
		radius_line.y *= -1;
		// Counterclockwise tangent vector
		tangent_line = glm::normalize(glm::vec2(-radius_line.y, radius_line.x));
	}
	else {
		// Clockwise tangent vector
		tangent_line = glm::normalize(glm::vec2(radius_line.y, -radius_line.x));
	}

	// add the offset to make the vector start at the input angle
	travel_x -= std::sin(input_angle);
	travel_y -= std::cos(input_angle);

	// scale this unit circle to the proper radius
	travel_x *= radius;
	travel_y *= radius;

	// flip x to make a left turn
	if (flipped_radius) {
		travel_y *= -1;
	}

	// convert to game space
	glm::vec3 gamespace_offset(-travel_y, vertical_movement, travel_x);
	tangent_line *= horizontal_movement;
	glm::vec3 tangent_3d(-tangent_line.y, vertical_movement, tangent_line.x);
	tangent_3d = glm::normalize(tangent_3d);
	tangent_3d *= glm::length(original_input_direction);

	// add to the position
	input_position += gamespace_offset;

	return {input_position, tangent_3d};
}
