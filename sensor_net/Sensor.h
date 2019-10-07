#pragma once
#include <chrono>

namespace bp
{

// Our fake sensor.  Generate data based on the cosine of the current system
// clock's time.  Can be customized by providing a scale factor and offset.
//
class Sensor
{
	private:
		const std::chrono::milliseconds sample_period_;
		const int scale_factor_;
		const int offset_;

	public:
		Sensor(const std::chrono::milliseconds sample_period, const int min_sensor_value, const int max_sensor_value);

		auto sample() const -> double;
		auto get_sample_period() const -> decltype(sample_period_);
};

}
