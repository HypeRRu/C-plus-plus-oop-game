#ifndef RANDOM_STUFF_GENERATOR_H
#define RANDOM_STUFF_GENERATOR_H

#include <ctime>
#include <cstdlib>

class RandomStuffGenerator
{
public:
	RandomStuffGenerator(
		size_t count_needed, 
		size_t possibilities
	);
	bool generateNew();
protected:
	size_t possibilities;
	size_t needed;
};

#endif