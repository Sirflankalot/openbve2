#include "util/math.hpp"
#include <glm/gtx/string_cast.hpp>
#include <iostream>

void print_evaluate_curve(const bve::util::math::EvaluateCurveState& val) {
	std::cout << "Position: " << to_string(val.position) << ", Tangent: " << to_string(val.tangent) << '\n';
}

void test_math() {
	auto const distance = 12.56637F * (5.0F / 4.0F) * (1.0F / 0.7071067811F);
	auto const val_a = bve::util::math::evaluate_curve(glm::vec3(0), glm::vec3(0, -1, 1), distance, -10);
	auto val_b = bve::util::math::evaluate_curve(val_a.position, val_a.tangent, distance, -10);
	val_b.tangent.y = 1;
	auto const val_c = bve::util::math::evaluate_curve(val_b.position, val_b.tangent, distance, -10);
	auto const val_d = bve::util::math::evaluate_curve(val_c.position, val_c.tangent, distance, -10);

	print_evaluate_curve(val_a);
	print_evaluate_curve(val_b);
	print_evaluate_curve(val_c);
	print_evaluate_curve(val_d);
}
