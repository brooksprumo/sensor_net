#pragma once
#include <csignal>

namespace bp
{
	using GoFlag = volatile std::sig_atomic_t;
}
