#include "LearnTemplate.h"



//多参数模板的取值方法
//ref:
//https://zh.cppreference.com/w/cpp/language/parameter_pack
//1.递归调用取值
void tprintf(const char *format) {
	std::cout << format;
}

template<typename T, typename... Targs>
void tprintf(const char *format, T value, Targs... Fargs) {
	for (; *format != '\0'; format++) {
		if (*format == '%') {
			std::cout << value;
			std::size_t val = sizeof...(Fargs);
			tprintf(format + 1, Fargs...); // 递归调用
			return;
		}
		std::cout << *format;
	}
}


//（1）一元右折叠
template<typename... Args>
auto add_val1(Args&&... args)
{
	return (args + ...);
}
template<typename... Args>
auto sub_val_right(Args&&... args)
{
	return (args - ...);
}

//（2）一元左折叠
template<typename... Args>
auto add_val2(Args&&... args)
{
	return (... + args);
}
template<typename... Args>
auto sub_val_left(Args&&... args)
{
	return (... - args);
}

//（3）二元左折叠
template<typename... Args>
auto sub_one_left(Args&&... args)
{
	return (1 - ... - args);
}
//1-(2-(3-4))=-2 错误
//(((1-2)-3)-4) = -8

//（4）二元右折叠
template<typename... Args>
auto sub_one_right(Args&&... args)
{
	return (args - ... - 1);
}
//((2-3)-4)-1=-6 错误
//(2-(3-(4-1))) = 2


LearnTemplate::LearnTemplate()
{
}

LearnTemplate::~LearnTemplate()
{
}

void LearnTemplate::run()
{
	int x1 = 0, y1 = 1;
	int result = add(x1, y1); 

	auto float_result = minus<float>(x1, y1);

	A<int> a;

	tprintf("% world% %\n", "Hello", '!', 123);

	std::vector<int> v;
	push_back_vec(v, 6, 2, 45, 13);
	push_back_vec(v, 1, 2, 9);
	for (int i : v)
		std::cout << i << ' ';

	std::cout << '\n' << std::endl;

	std::cout << add_val1(1, 2, 3, 4) << '\n';
	std::cout << add_val2(1, 2, 3, 4, 5, 6) << '\n';

	//右折叠:2-(3-4)=3
	//可以理解为args是取出的参数,...是待取出的参数包
	//从左至右依次取
	std::cout << sub_val_right(2, 3, 4) << '\n';
	//左折叠:(2-3)-4=-5
	//从右至左依次取
	std::cout << sub_val_left(2, 3, 4) << '\n';

	//二元左折叠
	std::cout << sub_one_left(2, 3, 4) << '\n';

	//二元右折叠
	std::cout << sub_one_right(2, 3, 4) << '\n';
}

