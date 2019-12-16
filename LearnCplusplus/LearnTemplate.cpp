#include "LearnTemplate.h"

LearnTemplate::LearnTemplate()
{
}

LearnTemplate::~LearnTemplate()
{
}

void LearnTemplate::run()
{
	int x1 = 0, y1 = 1;
	int result = add(x1, y1); 

	auto float_result = minus<float>(x1, y1);

	A<int> a;
}

