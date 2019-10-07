#include <algorithm>
#include <numeric>

#include "Buffer.h"

namespace bp
{

Buffer::Buffer(const size_t max_samples)
	: samples_( max_samples )
{
	// nothing to do here
}

void Buffer::add_sample(const double sample)
{
	samples_.push_back(sample);
}

auto Buffer::calculate_average() const -> double
{
	auto sum = std::reduce(std::cbegin(samples_), std::cend(samples_), 0.0);
	sum /= samples_.size();
	return sum;
}

auto Buffer::calculate_min() const -> double
{
	if (samples_.empty()) return 0;
	const auto min = std::min_element(std::cbegin(samples_), std::cend(samples_));
	return *min;
}

auto Buffer::calculate_max() const -> double
{
	if (samples_.empty()) return 0;
	const auto max = std::max_element(std::cbegin(samples_), std::cend(samples_));
	return *max;
}

auto Buffer::get_sample_count() const -> size_t
{
	return samples_.size();
}

}
