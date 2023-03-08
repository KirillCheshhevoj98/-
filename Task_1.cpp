#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;
/*
	Перегрузка и переопределение 
	Перегрузка методов - это возможность создания в одной области видимости несколько методов с одинаковыми именами, но с уникальным списком параметров.
	Рекомендуется использовать при наличии задачи, которая может быть реализована различными способами в зависимости от применяемого списка параметрами.
	Возвращаемый тип перегруженных методов может быть как одинаковым так и различным.
*/

class Car
{
private:
	string model;

protected:
	int speed;

public:
	Car()
	{
		this->model = "";
		this->speed = 0;
	}

	Car(string model, int speed)
	{
		this->model = model;
		setSpeed(speed);
	}

	Car(string model)
	{
		this->model = model;
		this->speed = 0;
	}

	void setModel(string model)
	{
		this->model = model;
	}

	string getModel()
	{
		return this->model;
	}

	void setSpeed(int speed)
	{
		if (speed > 0 && speed <= 220)
		{
			this->speed = speed;
		}
		else
		{
			this->speed = 0;
		}
	}

	int getSpeed()
	{
		return this->speed;
	}

	int calculatePrice()
	{
		return (this->speed * 100);
	}

	void update()
	{
		/*if ((this->speed + 5) <= 220)
		{
			this->speed += 5;
			cout << "Обновление успешно завершено" << endl;
		}
		else
		{
			this->speed = 220;
			cout << "Обновление достигло максимального порога" << endl;
		}*/

		update(5);
	}

	void update(int addSpeed)
	{
		if (addSpeed > 0 && addSpeed <= 15)
		{
			if ((this->speed + addSpeed) <= 220)
			{
				this->speed += addSpeed;
				cout << "Update completed successfully" << endl;
			}
			else
			{
				this->speed = 220;
				cout << "The update has reached the maximum threshold" << endl;
			}
		}
		else
		{
			cout << "Unable to update to the specified value" << endl;
		}
	}

	void ShowInfo()
	{
		cout << "Model car: " << this->model << endl
			<< "Speed: " << this->speed << endl
			<< "Price: " << calculatePrice() << endl;
	}

	~Car()
	{
	}
};

/*
	Переопределение методов - возможно при наличии наследовании.
	Переопределение методов - это возможность создания в производном классе метода с такими же типом, именем и списком парметров как и у методов базового класса.
	Рекомендуется применять при наличии одной и той же задачи, которая может быть выполнена различными способами в разных классах одной иерархии наследования.
*/
class SportCar : public Car
{
public:
	SportCar() {}

	SportCar(string model, int speed) : Car(model)
	{
		setSpeed(speed);
	}

	void setSpeed(int speed)
	{
		if (speed > 0 && speed <= 300)
		{
			this->speed = speed; // можем обратиться, т.к. поле speed - protected 
		}
		else
		{
			this->speed = 0;
		}
	}

	int calculatePrice()
	{
		return (this->speed * 250);
	}

	void update()
	{
		update(10);
	}

	void update(int addSpeed)
	{
		if (addSpeed > 0 && addSpeed <= 20)
		{
			if ((this->speed + addSpeed) <= 300)
			{
				this->speed += addSpeed;
				cout << "Update completed successfully" << endl;
			}
			else
			{
				this->speed = 300;
				cout << "The update has reached the maximum threshold" << endl;
			}
		}
		else
		{
			cout << "Unable to update to the specified value" << endl;
		}
	}

	void ShowInfo()
	{
		cout << "Model car: " << this->getModel() << endl
			<< "Speed: " << this->speed << endl
			<< "Price: " << calculatePrice() << endl;
	}

	~SportCar()
	{
	}
};
int main()
{
	Car* car1 = new Car("Mazda", 200);
	car1->ShowInfo();
	car1->update();
	car1->ShowInfo();
	car1->update(17);
	car1->ShowInfo();
	car1->update(12);
	car1->ShowInfo();
	car1->update(15);
	car1->ShowInfo();
	delete car1;
	car1 = NULL;

	cout << "-----------------------------------------" << endl;

	SportCar* sc1 = new SportCar("Porshe", 270);
	sc1->ShowInfo();
	sc1->update();
	sc1->ShowInfo();
	sc1->update(12);
	sc1->ShowInfo();
	sc1->update(25);
	sc1->ShowInfo();
	sc1->update(20);
	sc1->ShowInfo();
	delete sc1;
	sc1 = NULL;

	/*
		Множественное наследование - это попытка наследования сразу у нескольких классов.
		Это плохое проектирование классов из-за дублированного создания полей и неявностей вызова метода.
		Множественное наследование в Java реализованно при помощи ипримитированния интерфейса.
	*/
	system("pause");
	return 0;
}