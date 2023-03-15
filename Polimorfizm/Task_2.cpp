#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Pet
{
private:
	string nickname;
	int age;
public:

	Pet() :nickname(""), age(0) {};

	Pet(string nickname, int age)
	{
		this->nickname = nickname;
		this->age = age;
	}

	void setNickname(string nickname)
	{
		this->nickname = nickname;
	}

	string getNickname()
	{
		return this->nickname;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	int getAge()
	{
		return this->age;
	}

	virtual void voice() = 0; 
	// чистый виртуальный метод С++
	// абстрактный метод Java
	// класс Pet теперь абстрактный класс
	virtual void info() = 0;
	virtual ~Pet() {}
};

class Cat : public Pet
{
public:
	Cat() {};

	Cat(string nickname, int age) : Pet(nickname, age) {};

	void voice()
	{
		cout << "May May\n";
	}

	void info()
	{
		cout << "Nickname cat: " << getNickname() << endl
			<< "Age: " << getAge() << endl;
	}
	~Cat() {}
};

class Dog : public Pet
{
public:
	Dog() {};
	Dog(string nickname, int age) : Pet(nickname, age) {};

	void voice()
	{
		cout << "Gav Gav\n";
	}

	void info()
	{
		cout << "Nickname dog: " << getNickname() << endl
			<< "Age: " << getAge() << endl;
	}

	~Dog() {}
};

int main()
{
	Pet** pets = NULL; 
	int size = 5;
	pets = new Pet* [size];
	// Pet* pet1 = new Pet(); - невозможно создать объект абстрактного класса

	pets[0] = new Cat("Alesha", 1);
	pets[1] = new Dog("Petya", 2);
	pets[2] = new Cat("Ivan", 3);
	pets[3] = new Dog("Gys", 4);
	pets[4] = new Cat("Viskas", 5);

	for (int i = 0; i < size; i++)
	{
		cout << i << ") ";
		pets[i]->info();
		pets[i]->voice();
	}

	for (int i = 0; i < size; i++)
	{
		delete pets[i];
	}
	delete[] pets;
	system("pause");
	return 0;
}