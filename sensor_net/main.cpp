#include <atomic>
#include <cassert>
#include <chrono>
#include <csignal>
#include <memory>
#include <mutex>
#include <vector>

#include "GoFlag.h"
#include "SensorState.h"

using namespace std::literals::chrono_literals;

namespace
{
	bp::GoFlag go = true;
}

void handle_sigint([[maybe_unused]] int signal)
{
	::go = false;
	std::atomic_signal_fence(std::memory_order_release);
}

int main()
{
	std::atomic_signal_fence(std::memory_order_acquire);
	std::signal(SIGINT, handle_sigint);

	const auto reporter_period = 2s;
	std::mutex ostream_mutex;
	std::vector<std::unique_ptr<bp::SensorState>> sensors;
	sensors.emplace_back(std::make_unique<bp::SensorState>("Temperature",      0,     200, 1000ms, reporter_period, ::go, ostream_mutex));
	sensors.emplace_back(std::make_unique<bp::SensorState>("Pressure   ", 90'000, 110'000,  500ms, reporter_period, ::go, ostream_mutex));
	sensors.emplace_back(std::make_unique<bp::SensorState>("Flow Rate  ",      0,   1'000,   50ms, reporter_period, ::go, ostream_mutex));

	for (auto && sensor: sensors)
	{
		assert(sensor != nullptr);
		sensor->reporter_thread.join();
		sensor->sampler_thread.join();
	}

	return 0;
}
