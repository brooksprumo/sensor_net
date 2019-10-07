#pragma once
#include <boost/circular_buffer.hpp>

namespace bp
{

// Buffer for the sensor's data.  This class will also have the processing logic.
//
class Buffer
{
	public:
		explicit Buffer(const size_t max_samples);

		void add_sample(const double sample);
		auto calculate_average() const -> double;
		auto calculate_min() const -> double;
		auto calculate_max() const -> double;
		auto get_sample_count() const -> size_t;

	private:
		boost::circular_buffer<double> samples_;
};

}
