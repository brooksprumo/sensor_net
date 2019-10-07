#include <catch2/catch.hpp>
#include <sensor_net/Buffer.h>
#include <sensor_net/Reporter.h>

using namespace bp;

TEST_CASE("test Reporter")
{
	const auto max_samples = 4;
	Buffer buffer{max_samples};

	Reporter reporter{"Test", buffer};

	SUCCEED();
}
