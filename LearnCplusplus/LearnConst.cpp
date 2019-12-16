#include "LearnConst.h"

LearnConst::LearnConst()
{
}

LearnConst::~LearnConst()
{
}

void LearnConst::run()
{
	const int a = 1;
	// exception a为const，常数型数
	//a = 2;
	int const b = 2;
	// exception	b为const，常数型数
	//b = 3;

	const int *c = &a;
	// exception	c为const,指向长整型数的指针（所指向的内存数据不能修改，但本身可以修改）
	//*c = 4;

	int m = 1;
	int n = 2;
	int* const d = &m;
	// exception	int*为const，常量指针（指针变量不能被修改，但是它所指向内存空间可以被修改）
	//d = &n;
}
