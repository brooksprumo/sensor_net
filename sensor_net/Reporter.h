#pragma once
#include <atomic>
#include <chrono>
#include <mutex>
#include <string>

#include "GoFlag.h"

namespace bp
{

class Buffer; // forward-declare Buffer instead of #including its header file

class Reporter
{
	public:
		Reporter(std::string name, const Buffer & buffer);

		void operator()(const GoFlag & go, const std::chrono::milliseconds sleep_duration, std::mutex & ostream_mutex) const;

	private:
		void print(std::mutex & ostream_mutex) const;

	private:
		const std::string name_;
		const Buffer & buffer_;
};

}
