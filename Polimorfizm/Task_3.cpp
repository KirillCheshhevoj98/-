/*
	Параметризованные классы, шаблоны, дженерики

	class <тип1> имя{
		тип1 поле1;
		int поле2;
	}

	class <T> Box{
		T obj;
	}

	Box* <int> o1 = new Box();

	class <int> Box{
		int obj;
	}
*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>

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
	vector <Pet*> pets;
	int menu1 = 0, menu2 = 0;
	bool fExit = true;
	int age = 0;
	string nickname;


	pets.push_back(new Cat("Alesha", 1));
	pets.push_back(new Dog("Petya", 2));
	pets.push_back(new Cat("Ivan", 3));
	pets.push_back(new Dog("Gys", 4));
	pets.push_back(new Cat("Viskas", 5));

	do
	{
		cout << "1. Add" << endl;
		cout << "2. Print" << endl;
		cout << "3. Change" << endl;
		cout << "4. Remove" << endl;
		cout << "5. Sorting" << endl;
		cout << "6. Change owner" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter number of menu: " << endl;
		cin >> menu1;

		switch (menu1)
		{
			case 1: // добавление
			{
				cout << "Enter type of pet" << endl;
				cout << "1. Cat" << endl;
				cout << "2. Dog" << endl;
				cin >> menu2;

				cout << "Enter name pet" << endl;
				cin.ignore(INT_MAX, '\n');
				getline(cin, nickname);

				cout << "Enter age" << endl;
				cin >> age;

				switch (menu2)
				{
					case 1: // Cat
					{
						pets.push_back(new Cat(nickname, age));

						pets.insert(pets.begin(), new Cat(nickname, age));
					}
					break;

					case 2: // Dog
					{
						pets.push_back(new Dog(nickname, age));
 
						pets.insert(pets.begin(), new Dog(nickname, age));
					}
					break;

					default:
					{

					}
					break;
				}
			}
			break;

			case 2: // вывод
			{
				cout << "Conclusion: " << endl;
				for (int i = 0; i < pets.size(); i++)
				{
					cout << i + 1 << ") ";
					pets[i]->info();
					pets[i]->voice();
				}
			}
			break;

			case 3: // изменение
			{

			}
			break;

			case 4: // удаление
			{
				int num = 0;
				cout << "Enter number pet" << endl;
				cin >> num;

				delete pets[num - 1];
				pets.erase(pets.begin() + num - 1);
			}
			break;

			case 5: // сортировка
			{

			}
			break;

			case 6: // изменение хозяина
			{

			}
			break;

			case 7: // выход
			{

			}

			default:
			{

			}
			break;
		}

		system("pause");
		system("cls");
	} while (fExit);
	return 0;
}

