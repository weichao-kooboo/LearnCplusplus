#include "LearnConst.h"

LearnConst::LearnConst()
{
}

LearnConst::~LearnConst()
{
}

void LearnConst::run()
{
	const int a = 1;
	// exception aΪconst����������
	//a = 2;
	int const b = 2;
	// exception	bΪconst����������
	//b = 3;

	const int *c = &a;
	// exception	cΪconst,ָ����������ָ�루��ָ����ڴ����ݲ����޸ģ�����������޸ģ�
	//*c = 4;

	int m = 1;
	int n = 2;
	int* const d = &m;
	// exception	int*Ϊconst������ָ�루ָ��������ܱ��޸ģ���������ָ���ڴ�ռ���Ա��޸ģ�
	//d = &n;
}
