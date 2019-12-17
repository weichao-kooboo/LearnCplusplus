#pragma once
#ifndef _LEARN_TEMPLATE_H_INCLUDE_
#define	_LEARN_TEMPLATE_H_INCLUDE_

#include <iostream>
#include <vector>
#include <type_traits>
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

//变参数模板
template<typename... Us>
int add2(Us... pargs) {
	//cout << pargs << endl;
	std::size_t value = sizeof...(pargs);		//计算模板参数的总数
	return 1;
}
template<typename... ARGS>
int add1(ARGS... args) {
	add2(args...);	//add2中args就是模式,也可以使用&args取地址来当模式
	return -1;
}
//2.使用折叠表达式
//语法
//(形参包 op ...)	(1)
//(... op 形参包)	(2)
//(形参包 op ... op 初值)	(3)
//(初值 op ... op 形参包)	(4)
//1) 一元右折叠
//2) 一元左折叠
//3) 二元右折叠
//4) 二元左折叠
//op - 任何下列 32 个二元运算符之一： + -*/ % ^ & | = < > << >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .*->*。在二元折叠中，两个 op 必须相同。
//形参包 - 含未展开的形参包且其顶层不含有优先级低于转型（正式而言，是 转型表达式）的运算符的表达式
//初值 - 不含未展开的形参包且其顶层不含有优先级低于转型（正式而言，是 转型表达式）的运算符的表达式
//注意开与闭括号是折叠表达式的一部分。
//ref:
//https://zh.cppreference.com/w/cpp/language/fold
//这里需要设置c++17标准
//项目->属性->C/C++->所有选项->c++语言标准选择c++17
template<class... Args>
void printer(Args&&... args) {
	(std::cout << ... << args) << '\n';
}

template<class T,class... Args>
void push_back_vec(std::vector<T>& v, Args&&... args) {
	static_assert((std::is_constructible_v<T, Args&> && ...));
	(v.push_back(args), ...);
}


//muduo中多参数模板的使用方法,其中void(*CLASS::*function(ARGS...))表示一个function这个函数是CLASS里面,通过*function表示需要
//传地址比如&A::func,然后ARGS...表示function函数的传入参数.void表示function返回值类型
template<typename CLASS, typename... ARGS>
int makewc(void(CLASS::*function)(ARGS...)) {

}

class LearnTemplate {
public:
	LearnTemplate();
	~LearnTemplate();
	void run();
};

#endif // !_LEARN_TEMPLATE_H_INCLUDE_
