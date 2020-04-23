#pragma once

//��̬������������ж����˱��������ⲿ��ʼ��,��Ȼ��link��ʱ��ᱨ(�޷������Ķ������)
//ʾ��muduo/base/Singleton.h

	template<typename T>
	class Singleton
	{
	public:
		static T& instance()
		{
			_ins = new T();
			return *_ins;
		}
	private:
		Singleton() {}
		~Singleton() {}
		static T *_ins;
	};

	/*���������link��ʱ��ᱨ�޷���������Ĵ���*/
	template<typename T>
	T* Singleton<T>::_ins = 0;