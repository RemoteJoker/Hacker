#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <thread>
#include <mutex>

#include <chrono>

//�ṹ��
struct Test {};
struct Test_ {
	int a;
};

//������
union Test__ {
	int a;
	char c;
};

//ö��
enum Test___ {
	A,
	B,
	C
};

//��
class CA {};

class CV {
public:
	virtual ~CV() {};
};

class CF {
public:
	CF() {
		a = 4;
		std::cout << "����CF" << std::endl;
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
		std::cout << "����CC" << std::endl;
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

//����
void fun() {
	//ʵ��
	std::cout<<"hello world" << std::endl;
}
void fun_param(std::string str) {
	//ʵ��
	std::cout << str << std::endl;
}
void fun_param_ptr (std::string *str) {
	//ʵ��
	*str = "goodbye";
	std::cout << str << std::endl;
	std::cout << *str << std::endl;
}
void fun_param_quote(std::string &str) {
	//ʵ��
	str = "goodbye";
	std::cout << str << std::endl;
}

template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

int main() {
	/*
	һ.��������
	char:�ַ��ͣ�1�ֽ�
	short:�����Σ�2�ֽ�
	int:���Σ�4�ֽ�
	long:�����Σ�8�ֽ�
	float:�����ͣ�4�ֽ�
	double:˫���ȸ��㣻8�ֽ�
	*/
	char c = 'D';
	short s = 65535;
	int i = 4233333;
	long long l = 32132134354;//�˴�ע�⣬��Windowsƽ̨��һ��long��4�ֽڣ���Linux����8�ֽ�
	float f = 4.533;
	double d = 300.56356887;
	std::cout << sizeof(c) << std::endl;//1
	std::cout << sizeof(s) << std::endl;//2
	std::cout << sizeof(i) << std::endl;//4
	std::cout << sizeof(l) << std::endl;//8
	std::cout << sizeof(f) << std::endl;//4
	std::cout << sizeof(d) << std::endl;//8

	/*
	��.�������η�
	signed unsigned const static
	signed:�з��ţ�Ĭ��
	unsigned:�޷��ţ�������
	const:���峣��
	static:���徲̬����
	*/

	/*
	��.�ṹ��
	*/
	Test t;
	Test_ t_;
	std::cout << sizeof(t) << std::endl;//1
	std::cout << sizeof(t_) << std::endl;//4

	/*
	��.������
	*/
	Test__ t__;
	std::cout << sizeof(t__) << std::endl;//4
	t__.a = 4;
	std::cout << sizeof(t__) << std::endl;//4
	t__.c = 12;
	std::cout << sizeof(t__) << std::endl;//4

	/*
	��.ö��
	*/
	Test___ t___;
	std::cout << sizeof(t___) << std::endl;//4
	std::cout << A << std::endl;//0
	std::cout << B << std::endl;//1
	std::cout << C << std::endl;//2

	/*
	��.����
	*/
	fun();

	std::string str = "helloworld";
	fun_param(str);
	fun_param_ptr(&str);
	fun_param_quote(str);

	/*
	��.��������Լ��
	__cdecl:Ĭ��;����������;֧�ֿɱ����
	__stdcall:WindowsAPI;������������;��֧�ֿɱ����
	__fastcall:�Ĵ������ݲ���;������������
	__thiscall:���ԱĬ��;������������;thisָ��ͨ��ECX����
	__vectorcall:��
	*/

	/*
	��.��
	*/
	CA a;
	std::cout << sizeof(a) << std::endl;//1
	CV v;
	std::cout << sizeof(v) << std::endl;//8

	/*
	��.��װ
	*/
	int temp = 6;
	CF c_f;//������ջ��
	CF *p_f = new CF;//�����ڶ���
	c_f.SetA(temp);
	p_f->SetA(temp);

	/*
	ʮ.�̳�
	*/
	CC _c;

	/*
	ʮһ.��̬
	*/
	//����ʱ��̬--ģ��
	//����ʱ��̬--�麯��

	/*
	ʮ��.ģ��
	*/
	//����ģ��
	//��ģ��
	return 0;
}