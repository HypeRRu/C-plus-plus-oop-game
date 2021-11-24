#include "../../inc/utils/random_stuff_generator.h"

RandomStuffGenerator::RandomStuffGenerator(
	size_t count_needed, 
	size_t possibilities
):
	possibilities{possibilities}, 
	needed{count_needed}
{}

bool RandomStuffGenerator::generateNew()
{
	if (!this->needed)
		return false;
	std::srand(std::time(NULL) + this->possibilities);
	int offset = this->possibilities / this->needed;
	--this->possibilities;
	bool result = (std::rand() % offset) == 0;
	if (result)
		--this->needed;
	return result;
}

