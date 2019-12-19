#include "LearnSpace.h"

//外部无法访问
namespace detail{
	char require_32_bit_integer_at_least[sizeof(int) >= sizeof(__int32) ? 1 : -1];

	int getJulianDayNumber(int year, int month, int day)
	{
		(void)require_32_bit_integer_at_least; // no warning please
		int a = (14 - month) / 12;
		int y = year + 4800 - a;
		int m = month + 12 * a - 3;
		return day + (153 * m + 2) / 5 + y * 365 + y / 4 - y / 100 + y / 400 - 32045;
	}

}
const int LearnSpace::kA = detail::getJulianDayNumber(1970, 1, 1);

LearnSpace::LearnSpace()
{
}

int LearnSpace::Get()
{
	return 0;
}
