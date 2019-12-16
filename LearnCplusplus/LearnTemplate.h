#pragma once
#ifndef _LEARN_TEMPLATE_H_INCLUDE_
#define	_LEARN_TEMPLATE_H_INCLUDE_


//https://www.jianshu.com/p/fc3fe1e01b42
//函数模板
//参数自动推断
template<typename T>
T add(T x, T y) {
	return x + y;
}

//返回的参数类型需要显示提供
template<typename T1,typename T2>
T1 minus(T2 x, T2 y) {
	return x - y;
}

//类模板
template<typename T>
class A {
public:
	T getv() const { return V; }
private:
	T V;
};

class LearnTemplate {
public:
	LearnTemplate();
	~LearnTemplate();
	void run();
};

#endif // !_LEARN_TEMPLATE_H_INCLUDE_
