#include <chrono>
#include <cmath>

#include "Sensor.h"

namespace bp
{

Sensor::Sensor(const std::chrono::milliseconds sample_period, const int min_sensor_value, const int max_sensor_value)
	: sample_period_{sample_period}
	, scale_factor_{(max_sensor_value - min_sensor_value) / 2}
	, offset_{(max_sensor_value + min_sensor_value) / 2}
{
	// nothing to do here
}

auto Sensor::sample() const -> double
{
	return offset_ + scale_factor_ * std::cos(std::chrono::system_clock::now().time_since_epoch().count());
}

auto Sensor::get_sample_period() const -> decltype(sample_period_)
{
	return sample_period_;
}

}
