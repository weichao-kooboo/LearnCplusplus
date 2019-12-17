#pragma once
#ifndef _LEARN_TEMPLATE_H_INCLUDE_
#define	_LEARN_TEMPLATE_H_INCLUDE_

#include <iostream>
#include <vector>
#include <type_traits>
//https://www.jianshu.com/p/fc3fe1e01b42
//����ģ��
//�����Զ��ƶ�
template<typename T>
T add(T x, T y) {
	return x + y;
}

//���صĲ���������Ҫ��ʾ�ṩ
template<typename T1,typename T2>
T1 minus(T2 x, T2 y) {
	return x - y;
}

//��ģ��
template<typename T>
class A {
public:
	T getv() const { return V; }
private:
	T V;
};

//�����ģ��
template<typename... Us>
int add2(Us... pargs) {
	//cout << pargs << endl;
	std::size_t value = sizeof...(pargs);		//����ģ�����������
	return 1;
}
template<typename... ARGS>
int add1(ARGS... args) {
	add2(args...);	//add2��args����ģʽ,Ҳ����ʹ��&argsȡ��ַ����ģʽ
	return -1;
}
//2.ʹ���۵����ʽ
//�﷨
//(�βΰ� op ...)	(1)
//(... op �βΰ�)	(2)
//(�βΰ� op ... op ��ֵ)	(3)
//(��ֵ op ... op �βΰ�)	(4)
//1) һԪ���۵�
//2) һԪ���۵�
//3) ��Ԫ���۵�
//4) ��Ԫ���۵�
//op - �κ����� 32 ����Ԫ�����֮һ�� + -*/ % ^ & | = < > << >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .*->*���ڶ�Ԫ�۵��У����� op ������ͬ��
//�βΰ� - ��δչ�����βΰ����䶥�㲻�������ȼ�����ת�ͣ���ʽ���ԣ��� ת�ͱ��ʽ����������ı��ʽ
//��ֵ - ����δչ�����βΰ����䶥�㲻�������ȼ�����ת�ͣ���ʽ���ԣ��� ת�ͱ��ʽ����������ı��ʽ
//ע�⿪����������۵����ʽ��һ���֡�
//ref:
//https://zh.cppreference.com/w/cpp/language/fold
//������Ҫ����c++17��׼
//��Ŀ->����->C/C++->����ѡ��->c++���Ա�׼ѡ��c++17
template<class... Args>
void printer(Args&&... args) {
	(std::cout << ... << args) << '\n';
}

template<class T,class... Args>
void push_back_vec(std::vector<T>& v, Args&&... args) {
	static_assert((std::is_constructible_v<T, Args&> && ...));
	(v.push_back(args), ...);
}


//muduo�ж����ģ���ʹ�÷���,����void(*CLASS::*function(ARGS...))��ʾһ��function���������CLASS����,ͨ��*function��ʾ��Ҫ
//����ַ����&A::func,Ȼ��ARGS...��ʾfunction�����Ĵ������.void��ʾfunction����ֵ����
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
