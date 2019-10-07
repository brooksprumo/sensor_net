#include <cassert>
#include <iostream>
#include <thread>

#include "Reporter.h"
#include "Buffer.h"

namespace bp
{

Reporter::Reporter(std::string name, const Buffer & buffer)
	: name_{std::move(name)}
	, buffer_{buffer}
{
	// nothing to do here
}

void Reporter::operator()(const GoFlag & go, const std::chrono::milliseconds sleep_duration, std::mutex & ostream_mutex) const
{
	while (go)
	{
		print(ostream_mutex);
		std::this_thread::sleep_for(sleep_duration);
	}
}

void Reporter::print(std::mutex & ostream_mutex) const
{
	std::lock_guard lock{ostream_mutex};
	std::cout << name_
		<< ": min: " << buffer_.calculate_min()
		<< ", max: " << buffer_.calculate_max()
		<< ", average: " << buffer_.calculate_average()
		<< ", sample count: " << buffer_.get_sample_count()
		<< std::endl;
}

}
