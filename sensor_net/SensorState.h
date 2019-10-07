#pragma once
#include <atomic>
#include <chrono>
#include <csignal>
#include <mutex>
#include <string>
#include <thread>

#include "Buffer.h"
#include "GoFlag.h"
#include "Reporter.h"
#include "Sampler.h"
#include "Sensor.h"

namespace bp
{

class SensorState
{
	public:
		SensorState(std::string name, const int min_sensor_value, const int max_sensor_value, const std::chrono::milliseconds sample_period, const std::chrono::milliseconds reporter_period, const GoFlag & go, std::mutex & ostream_mutex);

	private:
		Sensor sensor_;
		Buffer buffer_;
		Sampler sampler_;
		Reporter reporter_;

	public:
		std::thread sampler_thread;
		std::thread reporter_thread;
};

}
