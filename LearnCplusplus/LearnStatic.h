#pragma once

//静态成语变量在类中定义了必须在类外部初始化,不然在link的时候会报(无法解析的对象错误)
//示例muduo/base/Singleton.h

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

	/*少了这句在link的时候会报无法解析对象的错误*/
	template<typename T>
	T* Singleton<T>::_ins = 0;