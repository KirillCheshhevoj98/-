#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;
/*
	���������� � ��������������� 
	���������� ������� - ��� ����������� �������� � ����� ������� ��������� ��������� ������� � ����������� �������, �� � ���������� ������� ����������.
	������������� ������������ ��� ������� ������, ������� ����� ���� ����������� ���������� ��������� � ����������� �� ������������ ������ �����������.
	������������ ��� ������������� ������� ����� ���� ��� ���������� ��� � ���������.
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
			cout << "���������� ������� ���������" << endl;
		}
		else
		{
			this->speed = 220;
			cout << "���������� �������� ������������� ������" << endl;
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
	��������������� ������� - �������� ��� ������� ������������.
	��������������� ������� - ��� ����������� �������� � ����������� ������ ������ � ������ �� �����, ������ � ������� ��������� ��� � � ������� �������� ������.
	������������� ��������� ��� ������� ����� � ��� �� ������, ������� ����� ���� ��������� ���������� ��������� � ������ ������� ����� �������� ������������.
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
			this->speed = speed; // ����� ����������, �.�. ���� speed - protected 
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
		������������� ������������ - ��� ������� ������������ ����� � ���������� �������.
		��� ������ �������������� ������� ��-�� �������������� �������� ����� � ���������� ������ ������.
		������������� ������������ � Java ������������ ��� ������ ���������������� ����������.
	*/
	system("pause");
	return 0;
}