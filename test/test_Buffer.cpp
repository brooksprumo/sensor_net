#include <catch2/catch.hpp>
#include <sensor_net/Buffer.h>

using namespace bp;

TEST_CASE("test Buffer")
{
	const auto max_samples = 4;
	Buffer buffer{max_samples};

	buffer.add_sample(4); // [4, -, -, -]
	CHECK(buffer.calculate_min() == 4);
	CHECK(buffer.calculate_max() == 4);
	CHECK(buffer.calculate_average() == 4);
	CHECK(buffer.get_sample_count() == 1);

	buffer.add_sample(2); // [2, 4, -, -]
	CHECK(buffer.calculate_min() == 2);
	CHECK(buffer.calculate_max() == 4);
	CHECK(buffer.calculate_average() == 3);
	CHECK(buffer.get_sample_count() == 2);

	buffer.add_sample(3); // [3, 2, 4, -]
	CHECK(buffer.calculate_min() == 2);
	CHECK(buffer.calculate_max() == 4);
	CHECK(buffer.calculate_average() == 3);
	CHECK(buffer.get_sample_count() == 3);

	buffer.add_sample(7); // [7, 3, 2, 4]
	CHECK(buffer.calculate_min() == 2);
	CHECK(buffer.calculate_max() == 7);
	CHECK(buffer.calculate_average() == 4);
	CHECK(buffer.get_sample_count() == 4);

	buffer.add_sample(8); // [8, 7, 3, 2]
	CHECK(buffer.calculate_min() == 2);
	CHECK(buffer.calculate_max() == 8);
	CHECK(buffer.calculate_average() == 5);
	CHECK(buffer.get_sample_count() == 4);

	buffer.add_sample(6); // [6, 8, 7, 3]
	CHECK(buffer.calculate_min() == 3);
	CHECK(buffer.calculate_max() == 8);
	CHECK(buffer.calculate_average() == 6);
	CHECK(buffer.get_sample_count() == 4);
}
