// LearnCplusplus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <functional>
#include <stdlib.h>

//#include "Cplusplus11.h"
//#include "LearnTemplate.h"
//#include "LearnSpace.h"

extern "C" {
#include "LearnLibevent.h"
}

//
////https://blog.csdn.net/u011068702/article/details/64443949
////func_test的参数const需要注意,不能省略
////c++语义限制,临时变量不能传入非const得引用
//template<typename CLASS,typename... ARGS>
//class func_test {
//public:
//	func_test(const std::function<void(CLASS*, ARGS...)>& function) :
//		function_(function) {
//
//	};
//private:
//	std::function<void(CLASS*, ARGS...)> function_;
//};
//
//template<typename CLASS,typename... ARGS>
//func_test<CLASS, ARGS...> makefunctest(void (CLASS::*function)(ARGS...)) {
//	return func_test<CLASS, ARGS...>(function);
//}
//
//class ctest{
//public:
//	void run() {
//
//	};
//};
//
//MyString Fun();
//void runRValue();
//
//class Mem_test{
//};
//class Mem_test1 {
//	int &a;
//};
//
//void exit_fn1(void) {
//	cout << "Exit function #1 called" << endl;
//}
//
//void exit_fn2(void) {
//	cout << "Exit function #2 called" << endl;
//}
//
//void atexit_test() {
//	//有8种方式使进程终止，其中前5种为正常终止，它们是
//	//	1：从 main 返回
//	//	2：调用 exit
//	//	3：调用 _exit 或 _Exit
//	//	4：最后一个线程从其启动例程返回
//	//	5：最后一个线程调用pthread_exit
//	//	异常终止有3种，它们是
//	//	6：调用 abort
//	//	7：接到一个信号并终止
//	//	8：最后一个线程对取消请求做出响应
//
//	//其中调用 _exit，_Exit 都不会调用终止程序
//	//异常终止也不会。
//	atexit(exit_fn1);
//	atexit(exit_fn2);
//}

#include "LearnSTL.h"

int main(int argc, char **argv)
{
	int k = 1;
	const int &f = k;
	printf("%d,%p,%p", f, &f, &k);
	k = 4; 
	printf("%d,%p", f, &f);

	int a[5] = { 1,2,3,4,5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", (a + 1), *(ptr - 1));

	system("pause");

	LearnSTL stl;

	int x = -1;
	unsigned int u = 2147483648;

	printf("x=%u=%d\n", x, x);

	printf("x=%u=%d\n", u, u);

	unsigned short s = 65535;
	unsigned short s1 = 65534;
	unsigned short s2 = s + s1;
	printf("s=%hu\n", s2);

	Sleep(1000000000000000);
	//run
	//run(argc, argv);


	//LearnSpace::Space s;
	//LearnSpace ls1;
	//LearnSpace ls2;
	//cout << LearnSpace::kA << endl;
	//cout << ls1.kA << endl;
	//cout << ls2.kA << endl;
	///*add1<int, float, double>(1, 1.2, 1.3);
	//tprintf("% world% %\n", "Hello", '!', 123);
	//runRValue();*/
	//cout << sizeof(Mem_test) << " " << sizeof(Mem_test1) << endl;

	//makefunctest(&ctest::run);
	// 
	////(void)d表示d转换为void类型,并且对其丢弃
	////ref:
	////https://www.cnblogs.com/litifeng/p/7753933.html
	//typedef char a[1];
	//a d;
	//(void)d;

	//atexit_test();
	//_exit(0);
	//LearnTemplate lt;
	//lt.run();
}



//
//MyString Fun()
//{
//	MyString str = "hello world";
//	return str;
//}
//
//void runRValue()
//{
//	//右值引用的概念,生成的一个临时变量，把这个临时变量给a,原本的a1的值不变. 
//	int &&a = 1;
//	int a1 = 2;
//	a = a1;
//	a++;
//	cout << a << a1 << endl;
//	MyString str1 = "123";
//	MyString str2 = str1;
//	MyString str3 = Fun();
//}
