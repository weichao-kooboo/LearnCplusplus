// LearnCplusplus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include "Cplusplus11.h"
#include "LearnTemplate.h"

MyString Fun();
void runRValue();

class Mem_test{
private:
	int k;
};

void exit_fn1(void) {
	cout << "Exit function #1 called" << endl;
}

void exit_fn2(void) {
	cout << "Exit function #2 called" << endl;
}

void atexit_test() {
	//有8种方式使进程终止，其中前5种为正常终止，它们是
	//	1：从 main 返回
	//	2：调用 exit
	//	3：调用 _exit 或 _Exit
	//	4：最后一个线程从其启动例程返回
	//	5：最后一个线程调用pthread_exit
	//	异常终止有3种，它们是
	//	6：调用 abort
	//	7：接到一个信号并终止
	//	8：最后一个线程对取消请求做出响应

	//其中调用 _exit，_Exit 都不会调用终止程序
	//异常终止也不会。
	atexit(exit_fn1);
	atexit(exit_fn2);
}

int main()
{
	/*add1<int, float, double>(1, 1.2, 1.3);
	tprintf("% world% %\n", "Hello", '!', 123);
	runRValue();*/

	Mem_test mt;
	bool value = sizeof(mt);
	atexit_test();
	_exit(0);
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
