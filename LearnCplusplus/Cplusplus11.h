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

//&& ����ֵ���õ�����
//1. �󶨵Ķ������õĶ��󣩲�ͬ����ֵ���ð󶨵��Ƿ�����ֵ���õĺ�������ֵ���±ꡢ�����á�ǰ�õ����ݼ�
//2. ��ֵ�־ã���ֵ���ݣ���ֵֻ�ܰ󶨵���ʱ���������õĶ���Ҫ���ٻ�ö���û�������û�
//3. ʹ����ֵ���õĴ���������ɵĽӹ������ö��������



int getVar();
class R {
	void run() {
		//��ֵ����,ֻ���ó�����ʼ��,������const int &a=1;
		int &&i = 1;
		int b = 2;
		//��ֵ����
		int &a = b;
		cout << i << endl;
		i = b;
		//ֱ�Ӱ�b�е�ֵ���Ƶ�i,���⸴�Ƶ�ʱ������ʱ����
		cout << i << endl;

		//��ֵ�����޷��󶨵���ֵ
		/*int&& temp = 0;
		int &&t = temp;*/

		//��ֵ ����ֱ�Ӵ�ֵ,�����½���ʱ����
		int &&bb = 1;
		int cc = 0;
		bb = cc;
		bb++;
		cout << cc << " " << bb << endl;


		//��ֵ����ֵ
		//��vs�в��ܽ������ѡ��(��RVO��NRVO)
		//int i = getVar();
		//����i����ֵ,getVar����ֵ
		int &c = b;
		//����c����ֵ����ֵ����
		int &&dd = 1;
		//��ֵ����ֱ�Ӱ���ֵ
		//ʹ��k��ֵ���ð���ֵ,���⹹��һ����ʱ����
		int&& k = getVar();
		//����:(��Ҫ���ñ���ѡ��-fno-elide-constructors�����رձ������Ż�)
		//-fno-elide-constructors��ʹ��:https://www.cnblogs.com/cvwyh/p/10735019.html
		//��vs�в��ܽ������ѡ��(��RVO��NRVO)
		//A a = GetA();

	};
};



//��ֵ����&&
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
