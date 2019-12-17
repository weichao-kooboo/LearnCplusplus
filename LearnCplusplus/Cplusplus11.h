#pragma once
#ifndef _LEARN_CPLUSPLUS_11_H_INCLUDE_
#define	_LEARN_CPLUSPLUS_11_H_INCLUDE_

#include <string>
#include <iostream>
using namespace std;

//ref:
//https://blog.csdn.net/li1914309758/article/details/81663488
//https://www.cnblogs.com/xiaobingqianrui/p/9064260.html
//https://www.jianshu.com/p/d19fc8447eaa

//&& 和左值引用的区别
//1. 绑定的对象（引用的对象）不同，左值引用绑定的是返回左值引用的函数、赋值、下标、解引用、前置递增递减
//2. 左值持久，右值短暂，右值只能绑定到临时对象，所引用的对象将要销毁或该对象没有其他用户
//3. 使用右值引用的代码可以自由的接管所引用对象的内容



int getVar();
class R {
	void run() {
		//右值引用,只能用常量初始化,类似于const int &a=1;
		int &&i = 1;
		int b = 2;
		//左值引用
		int &a = b;
		cout << i << endl;
		i = b;
		//直接把b中的值复制到i,避免复制的时候构造临时变量
		cout << i << endl;

		//右值引用无法绑定到左值
		/*int&& temp = 0;
		int &&t = temp;*/

		//右值 引用直接传值,不会新建临时变量
		int &&bb = 1;
		int cc = 0;
		bb = cc;
		bb++;
		cout << cc << " " << bb << endl;


		//左值和右值
		//在vs中不能禁用这个选项(即RVO和NRVO)
		//int i = getVar();
		//其中i是左值,getVar是右值
		int &c = b;
		//这是c当左值绑定左值引用
		int &&dd = 1;
		//右值引用直接绑定右值
		//使用k右值引用绑定右值,避免构造一次临时变量
		int&& k = getVar();
		//例子:(需要设置编译选项-fno-elide-constructors用来关闭编译器优化)
		//-fno-elide-constructors的使用:https://www.cnblogs.com/cvwyh/p/10735019.html
		//在vs中不能禁用这个选项(即RVO和NRVO)
		//A a = GetA();

	};
};



//右值引用&&
class MyString {
public:
	MyString();
	MyString(const char *pStr);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString &&other);
	MyString& operator=(MyString && other);
	~MyString();
private:
	void CopyData(const char* pData);
	void DeleteData();
private:
	char *m_pData;
	size_t m_nLen;
};

#endif // !_LEARN_CPLUSPLUS_11_H_INCLUDE_
