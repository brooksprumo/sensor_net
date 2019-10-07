#include <chrono>
#include <thread>

#include "Sampler.h"
#include "Buffer.h"
#include "Sensor.h"

namespace bp
{

Sampler::Sampler(const Sensor & sensor, Buffer & buffer)
	: sensor_{sensor}
	, buffer_{buffer}
{
	// nothing to do here
}

void Sampler::operator()(const GoFlag & go) const
{
	while (go)
	{
		buffer_.add_sample(sensor_.sample());
		std::this_thread::sleep_for(sensor_.get_sample_period());
	}
}

}
