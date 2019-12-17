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

//decltype�÷�
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

	//�˴���auto��ͬ
	//const double
	decltype(ctemp1) dclTemp1 = 4.1;
	//double
	auto dclauto1 = 4.1;

	decltype(cptrTemp1) dclTemp3 = &ctemp1;
	cout << sizeof(dclTemp3) << "    " << *dclTemp3 << endl;

	//�����ý��
	int t1 = 0, &reft1 = t1;

	decltype(reft1) refdclt1 = t1;
	//˫�����ű�ʾ����
	decltype((t1)) refdcl2 = t1;

	const int ct1 = 1, &creft1 = ct1;
	//const���ÿ��԰���ͨ����
	decltype(creft1) cdclTemp1 = t1;
	//const���ÿ��԰�const����
	decltype(creft1) cdclTemp2 = ct1;
	decltype(creft1) cdclTemp3 = 0;
	//˫�����ű�ʾ����
	decltype((ct1))  cdclTemp4 = ct1;

	//��ָ����
	int te1 = 2;
	int *ptrt1 = &te1;

	decltype(ptrt1) pdclTemp1;
	//���ʽ����Ϊ�����ò�����pdclTemp2Ϊһ�����ã����ñ����ʼ��
	//decltype(*ptrt1) pdclTemp2;

	//�ܽ�
	//decltype��auto�����������ƶ����ͣ����Ƕ����м������ԵĲ��죺
	//1.auto���Զ���const��decltype��������const��
	//2.�����ò�����auto�ƶϳ�ԭ�����ͣ�decltype�ƶϳ����ã�
	//3.�Խ����ò�����auto�ƶϳ�ԭ�����ͣ�decltype�ƶϳ����ã�
	//4.auto�ƶ�ʱ��ʵ��ִ�У�decltype����ִ�У�ֻ����������֮��ʹ���й����к�const�����ú�ָ����ʱ��Ҫ�ر�С��
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
