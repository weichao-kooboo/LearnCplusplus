#include "Cplusplus11.h"

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
