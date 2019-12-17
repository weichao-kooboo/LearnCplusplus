#include "Cplusplus11.h"

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;
struct A {
	A() {
		cout << "construct:" << ++g_constructCount << endl;
	}
	A(const A &a) {
		cout << "copy construct:" << ++g_copyConstructCount << endl;
	}
	~A() {
		cout << "destory:" << ++g_destructCount << endl;
	}
};

A GetA() {
	return A();
}

int getSize();

//decltype用法
//ref:
//https://www.cnblogs.com/ghbjimmy/p/10636030.html
void decltype_test() {
	int tempA = 2;
	//int
	decltype(tempA) dcltempA;
	//int
	decltype(getSize()) dcltempB;
	
	double temp1 = 3.0;
	const double ctemp1 = 5.0;
	const double ctemp2 = 6.0;
	const double *const cptrTemp1 = &ctemp1;

	//此处与auto不同
	//const double
	decltype(ctemp1) dclTemp1 = 4.1;
	//double
	auto dclauto1 = 4.1;

	decltype(cptrTemp1) dclTemp3 = &ctemp1;
	cout << sizeof(dclTemp3) << "    " << *dclTemp3 << endl;

	//与引用结合
	int t1 = 0, &reft1 = t1;

	decltype(reft1) refdclt1 = t1;
	//双层括号表示引用
	decltype((t1)) refdcl2 = t1;

	const int ct1 = 1, &creft1 = ct1;
	//const引用可以绑定普通变量
	decltype(creft1) cdclTemp1 = t1;
	//const引用可以绑定const变量
	decltype(creft1) cdclTemp2 = ct1;
	decltype(creft1) cdclTemp3 = 0;
	//双层括号表示引用
	decltype((ct1))  cdclTemp4 = ct1;

	//与指针结合
	int te1 = 2;
	int *ptrt1 = &te1;

	decltype(ptrt1) pdclTemp1;
	//表达式内容为解引用操作，pdclTemp2为一个引用，引用必须初始化
	//decltype(*ptrt1) pdclTemp2;

	//总结
	//decltype和auto都可以用来推断类型，但是二者有几处明显的差异：
	//1.auto忽略顶层const，decltype保留顶层const；
	//2.对引用操作，auto推断出原有类型，decltype推断出引用；
	//3.对解引用操作，auto推断出原有类型，decltype推断出引用；
	//4.auto推断时会实际执行，decltype不会执行，只做分析。总之在使用中过程中和const、引用和指针结合时需要特别小心
}


MyString::MyString():
	m_pData(NULL),
	m_nLen(0)
{
	cout << "MyString()" << endl;
}

MyString::MyString(const char * pStr)
{
	cout << "MyString(const char *pStr)" << endl;
	m_nLen = strlen(pStr);
	CopyData(pStr);
}

MyString::MyString(const MyString & other)
{
	cout << "MyString(const MyString& other)" << endl;
	if (!other.m_pData)
	{
		m_nLen = other.m_nLen;
		DeleteData();
		CopyData(other.m_pData);
	}
}

MyString & MyString::operator=(const MyString & other)
{
	cout << "MyString& operator=(const MyString& other)" << endl;
	if (this != &other)
	{
		m_nLen = other.m_nLen;
		DeleteData();
		CopyData(other.m_pData);
	}

	return *this;
}

MyString::MyString(MyString && other)
{
	cout << "MyString(MyString&& other)" << endl;
	m_nLen = other.m_nLen;
	m_pData = other.m_pData;
	other.m_pData = NULL;
}

MyString & MyString::operator=(MyString && other)
{
	cout << "MyString& operator=(const MyString&& other)" << endl;
	if (this != &other)
	{
		m_nLen = other.m_nLen;
		m_pData = other.m_pData;
		other.m_pData = NULL;
	}

	return *this;
}

MyString::~MyString()
{
	DeleteData();
}

void MyString::CopyData(const char * pData)
{
	if (pData)
	{
		m_pData = new char[m_nLen + 1];
		memcpy(m_pData, pData, m_nLen);
		m_pData[m_nLen] = '\0';
	}
}

void MyString::DeleteData()
{
	if (m_pData != NULL)
	{
		delete[] m_pData;
		m_pData = NULL;
	}
}

int getVar()
{
	return 0;
}
