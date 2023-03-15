#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class A
{
public:
	virtual void info() // включает механизм позднего связывания
	{
		cout << "Object class A\n";
	}
	virtual ~A()
	{
		cout << "Destructor A\n";
	}
};

class B : public A
{
public:
	void info()
	{
		cout << "Object class B\n";
	}

	void info1()
	{
		cout << "Object class B 11111";
	}
	~B()
	{
		cout << "Destructor B\n";
	}
};

class C : public B
{
public:
	void info()
	{
		cout << "Object class C\n";
	}
	~C()
	{
		cout << "Destructor C\n";
	}
};
int main()
{

	A* a1 = new A();
	B* b1 = new B();
	C* c1 = new C();

	a1->info();
	b1->info();
	b1->info1();
	c1->info();

	cout << "-------------------\n";

	A* base = NULL;
	
	// b1 = (B*)a1; 
	// нисходящее преобразование данныХ (downcast)
	// небезопасный, нужно быть уверенным в соответствении типов
	base = a1; // A* = A*
	base->info();
	delete base;
	cout << "-------------------\n";
	base = b1; // A* = (A*)B* - неявное преобразование
	base->info();
	delete base;
	cout << "-------------------\n";
	base = c1; // A* = (A*)C* - неявное преобразование
	// восходящее преобразование данных (upcast)
	// может работать и работает неявно; 
	// безопасно
	base->info();
	delete base;

	/*cout << "-------------------\n";
	delete a1, a1=NULL;

	cout << "-------------------\n";
	delete b1, b1 = NULL;

	cout << "-------------------\n";
	delete c1, c1 = NULL;*/

	
	system("pause");
	return 0;
}