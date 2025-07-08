#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <thread>
#include <mutex>

#include <chrono>

//结构体
struct Test {};
struct Test_ {
	int a;
};

//联合体
union Test__ {
	int a;
	char c;
};

//枚举
enum Test___ {
	A,
	B,
	C
};

//类
class CA {};

class CV {
public:
	virtual ~CV() {};
};

class CF {
public:
	CF() {
		a = 4;
		std::cout << "这是CF" << std::endl;
	};
	void SetA(int i) {
		a = i;
	}
	void GetA(int &i) {
		i = a;
	}
private:
	int a;
};

class CC : public CF {
public:
	CC() {
		std::cout << "这是CC" << std::endl;
	};
};

template <typename T>
class Stack {
private:
	std::vector<T> elements;
public:
	void push(const T& value) { elements.push_back(value); }
	T pop() {
		T top = elements.back();
		elements.pop_back();
		return top;
	}
};

//函数
void fun() {
	//实现
	std::cout<<"hello world" << std::endl;
}
void fun_param(std::string str) {
	//实现
	std::cout << str << std::endl;
}
void fun_param_ptr (std::string *str) {
	//实现
	*str = "goodbye";
	std::cout << str << std::endl;
	std::cout << *str << std::endl;
}
void fun_param_quote(std::string &str) {
	//实现
	str = "goodbye";
	std::cout << str << std::endl;
}

template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

int main() {
	/*
	一.数据类型
	char:字符型；1字节
	short:短整形；2字节
	int:整形；4字节
	long:长整形；8字节
	float:浮点型；4字节
	double:双精度浮点；8字节
	*/
	char c = 'D';
	short s = 65535;
	int i = 4233333;
	long long l = 32132134354;//此处注意，在Windows平台上一个long是4字节，在Linux上是8字节
	float f = 4.533;
	double d = 300.56356887;
	std::cout << sizeof(c) << std::endl;//1
	std::cout << sizeof(s) << std::endl;//2
	std::cout << sizeof(i) << std::endl;//4
	std::cout << sizeof(l) << std::endl;//8
	std::cout << sizeof(f) << std::endl;//4
	std::cout << sizeof(d) << std::endl;//8

	/*
	二.语言修饰符
	signed unsigned const static
	signed:有符号，默认
	unsigned:无符号，正整数
	const:定义常量
	static:定义静态变量
	*/

	/*
	三.结构体
	*/
	Test t;
	Test_ t_;
	std::cout << sizeof(t) << std::endl;//1
	std::cout << sizeof(t_) << std::endl;//4

	/*
	四.联合体
	*/
	Test__ t__;
	std::cout << sizeof(t__) << std::endl;//4
	t__.a = 4;
	std::cout << sizeof(t__) << std::endl;//4
	t__.c = 12;
	std::cout << sizeof(t__) << std::endl;//4

	/*
	五.枚举
	*/
	Test___ t___;
	std::cout << sizeof(t___) << std::endl;//4
	std::cout << A << std::endl;//0
	std::cout << B << std::endl;//1
	std::cout << C << std::endl;//2

	/*
	六.函数
	*/
	fun();

	std::string str = "helloworld";
	fun_param(str);
	fun_param_ptr(&str);
	fun_param_quote(str);

	/*
	七.函数调用约定
	__cdecl:默认;调用者清理;支持可变参数
	__stdcall:WindowsAPI;被调用者清理;不支持可变参数
	__fastcall:寄存器传递参数;被调用者清理
	__thiscall:类成员默认;被调用者清理;this指针通过ECX传递
	__vectorcall:新
	*/

	/*
	八.类
	*/
	CA a;
	std::cout << sizeof(a) << std::endl;//1
	CV v;
	std::cout << sizeof(v) << std::endl;//8

	/*
	九.封装
	*/
	int temp = 6;
	CF c_f;//创建在栈上
	CF *p_f = new CF;//创建在堆上
	c_f.SetA(temp);
	p_f->SetA(temp);

	/*
	十.继承
	*/
	CC _c;

	/*
	十一.多态
	*/
	//编译时多态--模板
	//运行时多态--虚函数

	/*
	十二.模板
	*/
	//函数模板
	//类模板
	return 0;
}