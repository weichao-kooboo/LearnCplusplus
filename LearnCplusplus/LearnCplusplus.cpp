// LearnCplusplus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include "Cplusplus11.h"
#include "LearnTemplate.h"

MyString Fun();
void runRValue();

int main()
{
	/*add1<int, float, double>(1, 1.2, 1.3);
	tprintf("% world% %\n", "Hello", '!', 123);
	runRValue();*/

	LearnTemplate lt;
	lt.run();
}

MyString Fun()
{
	MyString str = "hello world";
	return str;
}

void runRValue()
{
	//右值引用的概念,生成的一个临时变量，把这个临时变量给a,原本的a1的值不变. 
	int &&a = 1;
	int a1 = 2;
	a = a1;
	a++;
	cout << a << a1 << endl;
	MyString str1 = "123";
	MyString str2 = str1;
	MyString str3 = Fun();
}
