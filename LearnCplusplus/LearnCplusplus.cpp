// LearnCplusplus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

//ref:
//https://www.cnblogs.com/cthon/p/9166715.html,
//https://www.cnblogs.com/cthon/p/9178701.html,
//https://segmentfault.com/a/1190000018096022

int main()
{
    std::cout << "Hello World!\n"; 

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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
