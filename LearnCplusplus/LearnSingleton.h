#pragma once
#ifndef _LEARN_SINGLETON_H_INCLUDE_
#define	_LEARN_SINGLETON_H_INCLUDE_

#include <stdlib.h>
#include <stdint.h>

//�ж������Ƿ����no_destory����
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
		//�������no_destory����,�Ͳ����ٸõ���
		//�����������һֱ�ڳ�����,����ĳ����Χ�ڱ�����
		//windows��û��ʵ��,linux�Ͽ�������
		if (!has_no_destroy<T>::value) {
			::atexit(destroy);
		}
	}

	static void destroy() {
		//һ���������û�г�Ա����,��ôsizeof(class)=1,1���ֽڱ�ʾ����Ĵ�С,�����������Ա,����:int &i,��ôsizeof(class)=4.
		//4���ֽڱ�ʾint�Ĵ�С
		//����:
		//class Mem_test {
		//};
		//class Mem_test1 {
		//	int &a;
		//};
		//cout << sizeof(Mem_test) << " " << sizeof(Mem_test1) << endl;
		//(void)dummy��ʾdummyת��Ϊvoid����,���Ҷ��䶪��
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
