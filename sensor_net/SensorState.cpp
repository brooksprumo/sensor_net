#include "SensorState.h"

namespace bp
{

SensorState::SensorState(std::string name, const int min_sensor_value, const int max_sensor_value, const std::chrono::milliseconds sample_period, const std::chrono::milliseconds reporter_period, const GoFlag & go, std::mutex & ostream_mutex)
	: sensor_{sample_period, min_sensor_value, max_sensor_value}
	, buffer_{static_cast<size_t>(reporter_period.count() / sample_period.count())}
	, sampler_{sensor_, buffer_}
	, reporter_{std::move(name), buffer_}
	, sampler_thread{std::ref(sampler_), std::ref(go)}
	, reporter_thread{std::ref(reporter_), std::ref(go), reporter_period, std::ref(ostream_mutex)}
{
	// nothing to do here
}

}
