#include <catch2/catch.hpp>
#include <sensor_net/Sensor.h>

using namespace std::literals::chrono_literals;
using namespace bp;

TEST_CASE("test Sensor")
{
	const auto min_sensor_value = 10;
	const auto max_sensor_value = 20;
	Sensor sensor{200ms, min_sensor_value, max_sensor_value};

	for (auto i = 0; i != 10'000; ++i)
	{
		const auto sample = sensor.sample();
		CHECK(sample >= min_sensor_value);
		CHECK(sample < max_sensor_value);
	}
}
