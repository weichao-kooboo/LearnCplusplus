#pragma once
#ifndef _LEARN_SINGLETON_H_INCLUDE_
#define	_LEARN_SINGLETON_H_INCLUDE_

#include <stdlib.h>
#include <stdint.h>

//判断类中是否存在no_destory方法
template<typename T>
struct has_no_destroy {
	template<typename C>
	static char test(decltype(&C::no_destory));
	template<typename C>
	static int32_t test(...);
	cosnt static bool value = sizeof(test<T>(0)) == 1;
};

template<typename T>
class Singleton {
public:
	Singleton() = delete;
	~Singleton() = delete;

	static T& instance() {
		init();
		return *value_;
	}
private:
	static void init() {
		value_ = new T();
		//如果存在no_destory方法,就不销毁该单例
		//保持这个单例一直在程序中,不在某个范围内被销毁
		//windows上没有实践,linux上可以试试
		if (!has_no_destroy<T>::value) {
			::atexit(destroy);
		}
	}

	static void destroy() {
		//一个类中如果没有成员变量,那么sizeof(class)=1,1个字节表示空类的大小,如果有其他成员,比如:int &i,那么sizeof(class)=4.
		//4个字节表示int的大小
		//例如:
		//class Mem_test {
		//};
		//class Mem_test1 {
		//	int &a;
		//};
		//cout << sizeof(Mem_test) << " " << sizeof(Mem_test1) << endl;
		//(void)dummy表示dummy转换为void类型,并且对其丢弃
		//ref:
		//https://www.cnblogs.com/litifeng/p/7753933.html
		typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
		T_must_be_complete_type dummy; (void)dummy;

		delete value_;
		value_ = NULL;
	}
private:
	static T* value_;
};

#endif // !_LEARN_SINGLETON_H_INCLUDE_
