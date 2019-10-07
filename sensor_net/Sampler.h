#pragma once
#include <atomic>

#include "GoFlag.h"

namespace bp
{

class Buffer;
class Sensor;

class Sampler
{
	public:
		Sampler(const Sensor & sensor, Buffer & buffer);

		void operator()(const GoFlag & go) const;

	private:
		const Sensor & sensor_;
		Buffer & buffer_;
};

}
