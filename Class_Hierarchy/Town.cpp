#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Region
{
private:
	string title_region;
	double square;

public:
	Region()
	{
		this->title_region = "";
		this->square = 0;
	}

	Region(string title_region, double square)
	{
		this->title_region = title_region;
		this->square = square;
	}

	void setTitle_region(string title_region)
	{
		this->title_region = title_region;
	}

	string getTitle_region()
	{
		return this->title_region;
	}

	void setSquare(double square)
	{
		this->square = square;
	}

	double getSquare()
	{
		return this->square;
	}

	void infoRegion()
	{
		cout << "Title region: " << this->title_region
			<< ", square: " << this->square << endl;
	}

	~Region()
	{
		cout << "Working destructor Region" << endl;
	}
};

class City : public Region
{
private:
	string title_city;
	double number_of_population;
public:
	City() : Region()
	{
		this->title_city = "";
		this->number_of_population = 0;
	}

	City(string title_region, double square, string title_city, double number_of_population) :Region(title_region, square)
	{
		setTitle_region(title_region);
		setSquare(square);
		this->title_city = title_city;
		this->number_of_population = number_of_population;
	}

	void setTitle_city(string title_city)
	{
		this->title_city = title_city;
	}

	string getTitle_city()
	{
		return this->title_city;
	}

	void setNumber_of_population(double number_of_population)
	{
		this->number_of_population = number_of_population;
	}

	double getNumber_of_population()
	{
		return this->number_of_population;
	}
	void infoCity()
	{
		cout << "Title region: " << this->getTitle_region()
			<< ", square: " << this->getSquare()
			<< ", title city: " << this->title_city
			<< ", population: " << this->number_of_population << endl;
	}

	~City()
	{
		cout << "Working destructor City" << endl;
	}
};

class Metropolis : public City
{
private:
	string title_metropolis;
public:
	Metropolis() :City()
	{
		this->title_metropolis = "";
	}

	Metropolis(string title_region, double square, string title_city, double number_of_population, string title_metropolis) : City(title_region, square, title_city,number_of_population)
	{
		setTitle_region(title_region);
		setSquare(square);
		setTitle_city(title_city);
		setNumber_of_population(number_of_population);
		this->title_metropolis = title_metropolis;
	}

	void setTitle_metropolis(string title_metropolis)
	{
		this->title_metropolis = title_metropolis;
	}

	string getTitle_metropolis()
	{
		return this->title_metropolis;
	}

	void infoMetropolis()
	{
		cout << "Title region: " << this->getTitle_region()
			<< ", square: " << this->getSquare()
			<< ", title city: " << this->getTitle_city()
			<< ", population: " << this->getNumber_of_population() 
			<< ", title metropolis: " << this->title_metropolis << endl;
	}

	~Metropolis ()
	{
		cout << "Working destructor Metropolis" << endl;
	}
};

class Place :public City
{
private:
	string address;
public:
	Place() :City()
	{
		this->address = "";
	}

	Place(string title_region, double square, string title_city, double number_of_population, string address) :City(title_region, square, title_city, number_of_population)
	{
		setTitle_region(title_region);
		setSquare(square);
		setTitle_city(title_city);
		setNumber_of_population(number_of_population);
		this->address = address;
	}

	void setAddress(string address)
	{
		this->address = address;
	}

	string getAddress()
	{
		return this->address;
	}

	void infoPlace()
	{
		cout << "Title region: " << this->getTitle_region()
			<< ", square: " << this->getSquare()
			<< ", title city: " << this->getTitle_city()
			<< ", population: " << this->getNumber_of_population()
			<< ", address place: " << this->address << endl;
	}

	~Place()
	{
		cout << "Working destructor Place" << endl;
	}
};

int main()
{
	Region* r1 = new Region("Gomelskaya", 100.00);
	r1->infoRegion();
	delete r1;
	r1 = NULL;

	cout << "----";

	City* city1 = new City("Minskakya", 10.0, "Bobs", 10.0);
	city1->infoCity();
	delete city1;
	city1 = NULL;

	cout << "----";

	Metropolis* metropolis1 = new Metropolis("Vitebsk", 2.00, "Pokalubishi", 7, "Vetka");
	metropolis1->infoMetropolis();
	delete metropolis1;
	metropolis1 = NULL;

	Place* place1 = new Place("Minskakya", 10.0, "Bobs", 10.0,"Sovetskay 1");
	place1->infoPlace();
	delete place1;
	place1 = NULL;

	system("pause");
	return 0;
}