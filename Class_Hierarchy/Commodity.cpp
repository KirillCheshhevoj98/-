#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Commodity
{
private:
	string name;
	double salary;

public:
	Commodity()
	{
		this->name = "";
		this->salary = 0;
	}

	Commodity(string name, double salary)
	{
		this->name = name;
		this->salary = salary;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return this->name;
	}

	void setSalary(double salary)
	{
		this->salary = salary;
	}

	double getSalary()
	{
		return this->salary;
	}

	void infoCommodity()
	{
		cout << "Name product: " << this->name
			<< ", salary: " << this->salary << endl;
	}

	~Commodity()
	{
		cout << "Working destructor Commodity" << endl;
	}
};

class Product : public Commodity
{
private:
	string purpose;
public:
	Product() : Commodity()
	{
		this->purpose = "";
	}

	Product(string name, double salary, string purpose) :Commodity(name, salary)
	{
		setName(name);
		setSalary(salary);
		this->purpose = purpose;
	}

	void setPurpose(string purpose)
	{
		this->purpose = purpose;
	}

	string getPurpose()
	{
		return this->purpose;
	}

	void infoProduct()
	{
		cout << "Name product: " << this->getName()
			<< ", salary: " << this->getSalary()
			<< ", purpose: " << this->purpose << endl;
	}

	~Product()
	{
		cout << "Working destructor Product" << endl;
	}
};

class Dairy_Product : public Product
{
private:
	int expiration_date;
public:
	Dairy_Product() :Product()
	{
		this->expiration_date = 0;
	}

	Dairy_Product(string name, double salary, string purpose, int expiration_date) : Product(name, salary, purpose)
	{
		setName(name);
		setSalary(salary);
		setPurpose(purpose);
		this->expiration_date = expiration_date;
	}

	void setExpiration_date(int expiration_date)
	{
		this->expiration_date = expiration_date;
	}

	int getExpiration_date()
	{
		return this->expiration_date;
	}

	void infoDairy_Product()
	{
		cout << "Name product: " << this->getName()
			<< ", salary: " << this->getSalary()
			<< ", purpose: " << this->getPurpose()
			<< ", expiration date: " << this->expiration_date << endl;
	}

	~Dairy_Product()
	{
		cout << "Working destructor Dairy product" << endl;
	}
};

class Toy :public Commodity
{
private:
	int age;
public:
	Toy() :Commodity()
	{
		this->age = 0;
	}

	Toy(string name, double salary, int age) :Commodity(name, salary)
	{
		setName(name);
		setSalary(salary);
		this->age = age;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	int getAge()
	{
		return this->age;
	}

	void infoToy()
	{
		cout << "Name product: " << this->getName()
			<< ", salary: " << this->getSalary()
			<< ", age: " << this->age << endl;
	}

	~Toy()
	{
		cout << "Working destructor Toy" << endl;
	}
};

int main()
{
	Commodity* c1 = new Commodity("Shirt", 5.00);
	c1->infoCommodity();
	delete c1;
	c1 = NULL;

	cout << "----";

	Product* product1 = new Product("Banan", 10.0, "food");
	product1->infoProduct();
	delete product1;
	product1 = NULL;

	cout << "----";

	Dairy_Product* dairy_product1 = new Dairy_Product("Milk", 2.00, "dairy product", 7);
	dairy_product1->infoDairy_Product();
	delete dairy_product1;
	dairy_product1 = NULL;

	Toy* toy1 = new Toy("Car", 15.00, 3);
	toy1->infoToy();
	delete toy1;
	toy1 = NULL;

	system("pause");
	return 0;
}