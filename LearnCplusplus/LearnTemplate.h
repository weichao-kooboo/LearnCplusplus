#pragma once
#ifndef _LEARN_TEMPLATE_H_INCLUDE_
#define	_LEARN_TEMPLATE_H_INCLUDE_


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

class LearnTemplate {
public:
	LearnTemplate();
	~LearnTemplate();
	void run();
};

#endif // !_LEARN_TEMPLATE_H_INCLUDE_
