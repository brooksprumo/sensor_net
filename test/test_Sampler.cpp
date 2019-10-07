#include <catch2/catch.hpp>
#include <sensor_net/Buffer.h>
#include <sensor_net/Sampler.h>
#include <sensor_net/Sensor.h>

using namespace bp;

TEST_CASE("test Sensor")
{
	const auto min_sensor_value = 10;
	const auto max_sensor_value = 20;
	Sensor sensor{200ms, min_sensor_value, max_sensor_value};

	const auto max_samples = 4;
	Buffer buffer{max_samples};

	Sampler sampler{sensor, buffer};

	SUCCEED();
}
