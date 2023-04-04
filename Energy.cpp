#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Energy {
private:
	string nameClient;
	int quantity;
public:
	int priority = 0;
	double costEnergy = 0;
	int costOrdinaryEnergy = 15;
	Energy() : nameClient(""), quantity(0) {}
	Energy(string nameClient,int quantity) {
		this->nameClient = nameClient;
		this->quantity = quantity;
	}

	void setNameClient() {
		this->nameClient = nameClient;
	}

	string getNameClient() {
		return nameClient;
	}

	void setQuantity() {
		this->quantity = quantity;
	}

	int getQuantity() {
		return quantity;
	}

	virtual int getPriority() = 0;

	virtual void info() = 0;
	virtual double electricity_bill() = 0;
	static bool sortBillEnergy(Energy* energy1, Energy* energy2) {
		if (energy1->quantity > energy2->quantity) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool sortCostEnergy(Energy* energy1, Energy* energy2) {
		if (energy1->electricity_bill() > energy2->electricity_bill()) {
			return false;
		}
		else {
			return true;
		}
	}
	static bool sortPriority(Energy* energy1, Energy* energy2) {
		if (energy1->getPriority() < energy2->getPriority()) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual ~Energy() {};
};

class Ordinary : public Energy {
public:
	Ordinary() {};
	Ordinary(string nameClient,int quantity) : Energy(nameClient, quantity) {};
	
	double electricity_bill() {
		costEnergy = getQuantity() * costOrdinaryEnergy;
		return costEnergy;
	}

	int getPriority() {
		return priority = 1;
	}

	void info() {
		cout << "Client: " << getNameClient() << endl
			<< "Categorie: ordinary" << endl
			<< "Amount of energy: " << getQuantity() << endl
			<< "The cost of one unit energy: " << costOrdinaryEnergy << endl
			<< "Total cost " << electricity_bill() << endl;
	}
};


class Limit : public Energy {
private:
	static int costLimitEnergy;
	static int limitEnergy;
public:
	Limit() {};
	Limit(string nameClient, int quantity) : Energy(nameClient, quantity) {};

	double electricity_bill() {
		if (getQuantity() > limitEnergy) {
			costEnergy = limitEnergy * costOrdinaryEnergy + (getQuantity() - limitEnergy) * costLimitEnergy;
		}
		else { 
			costEnergy = getQuantity() * costOrdinaryEnergy;
		}
		return costEnergy;
	}

	int getPriority() {
		return priority = 2;
	}

	void info() {
		cout << "Client: " << getNameClient() << endl
			<< "Categorie: limit" << endl
			<< "Amount of energy: " << getQuantity() << endl
			<< "The cost of one unit is over " << limitEnergy << ": " << costLimitEnergy << endl
			<< "Total cost " << electricity_bill() << endl;
	}
};

int Limit::costLimitEnergy = 20;
int Limit::limitEnergy = 250;

class Preferential : public Energy {
private:
	static int costPreferentialEnergy;
public:
	Preferential() {};
	Preferential(string nameClient, int quantity) : Energy(nameClient, quantity) {};

	double electricity_bill() {
		costEnergy = getQuantity() * costPreferentialEnergy;
		return costEnergy;
	}

	int getPriority() {
		return priority = 3;
	}

	void info() {
		cout << "Client: " << getNameClient() << endl
			<< "Categorie: preferential" << endl
			<< "Amount of energy: " << getQuantity() << endl
			<< "The cost of one unit energy: " << costPreferentialEnergy << endl
			<< "Total cost " << electricity_bill() << endl;
	}
};

int Preferential::costPreferentialEnergy = 10;

class HeatingNeeds : public Energy {
private:
	static int costHeatingNeedsEnergy;
public:
	HeatingNeeds() {};
	HeatingNeeds(string nameClient, int quantity) : Energy(nameClient, quantity) {};

	double electricity_bill() {
		costEnergy = getQuantity() * costHeatingNeedsEnergy;
		return costEnergy;
	}

	int getPriority() {
		return priority = 4;
	}

	void info() {
		cout << "Client: " << getNameClient() << endl
			<< "Categorie: heating needs" << endl
			<< "Amount of energy: " << getQuantity() << endl
			<< "The cost of one unit energy: " << costHeatingNeedsEnergy << endl
			<< "Total cost " << electricity_bill() << endl;
	}
};

int HeatingNeeds::costHeatingNeedsEnergy = 1;

int main() {
	vector <Energy*> energy;
	int menu;
	bool fExit = true;
	double sumCostEnergy = 0;
	double sumCostAllEnergyOrdinary = 0;
	int costEnergyOrdinary = 15;


	energy.push_back(new Ordinary("GomSelmash", 30));
	energy.push_back(new Limit("Home 1", 300));
	energy.push_back(new Preferential("Minsk", 3000));
	energy.push_back(new HeatingNeeds("Vitebsk", 4000));

	energy.push_back(new Ordinary("Masha", 60));
	energy.push_back(new Limit("Home 2", 600));
	energy.push_back(new Preferential("Mogilev", 1500));
	energy.push_back(new HeatingNeeds("Haitek", 990));

	energy.push_back(new Ordinary("Bobryisk", 10000));
	energy.push_back(new Limit("Home 3", 200));
	energy.push_back(new Preferential("Ilya", 30));
	energy.push_back(new HeatingNeeds("Kirill", 30));



	for (int i = 0; i < energy.size(); i++) {
		energy[i]->info();
	}


	do
	{
		cout << "1. Sort the array by the amount of energy consumed by customers in descending order." << endl;
		cout << "2. Sort the array by the amount of payment by customers in ascending order." << endl;
		cout << "3. Arrange the array by type of customers (first Ц regular, then Ц with a limit, then Ц preferential and last Ц for heating needs)." << endl;
		cout << "4. Calculate the total SUM of all customers' payments for the energy consumed." << endl;
		cout << "5. Calculate the total amount of benefits." << endl;
		cout << "6. Exit." << endl;

		cin >> menu;

		switch (menu) {
			case 1: { // ќтсортировать массив по количеству потреблЄнной клиентами энергии по убыванию.
				sort(energy.begin(), energy.end(), Energy::sortBillEnergy);
				for (int i = 0; i < energy.size(); i++) {
					cout << "Client: " << energy[i]->getNameClient() << endl;
					cout << "Quantity energy: " << energy[i]->getQuantity() << endl;
				}
			}
			break;

			case 2: { //	ќтсортировать массив по величине оплаты клиентами по возрастанию.
				sort(energy.begin(), energy.end(), Energy::sortCostEnergy);
				for (int i = 0; i < energy.size(); i++) {
					cout << "Client: " << energy[i]->getNameClient() << endl;
					cout << "Electricity bill: " << energy[i]->electricity_bill() << endl;
				}
			}
		    break;

			case 3: { // ”пор€дочить массив по типу клиентов (первыми Ц обычные, затем Ц с лимитом, затем Ц льготные и последними Ц дл€ нужд отоплени€)
				sort(energy.begin(), energy.end(), Energy::sortPriority);
				for (int i = 0; i < energy.size(); i++) {
					cout << "Client: " << energy[i]->getNameClient() << endl;
					cout << "Electricity bill: " << energy[i]->electricity_bill() << endl;
				}
			}
		    break;

			case 4: { // ¬ычислить общую сумму SUM оплаты всех клиентов за потреблЄнную энергию.
				sumCostEnergy = 0;
				for (int i = 0; i < energy.size(); i++) {
					sumCostEnergy += energy[i]->electricity_bill();
				}
				cout << "The total sum of all customers' payments for the energy consumed: " << sumCostEnergy << endl;
			}
			break;

			case 5: { // ¬ычислить общий размер льготы LG=SUM0ЦSUM. √де SUM0 Ц обща€ сумма оплаты всех клиентов за потребленную энергию, если бы они все были обычными (без льгот и лимитов).
				
				sumCostAllEnergyOrdinary = 0;
				sumCostEnergy = 0;
				for (int i = 0; i < energy.size(); i++) {
					sumCostAllEnergyOrdinary += energy[i]->getQuantity();
				}

				for (int i = 0; i < energy.size(); i++) {
					sumCostEnergy += energy[i]->electricity_bill();
				}
				sumCostAllEnergyOrdinary = sumCostAllEnergyOrdinary * costEnergyOrdinary;
				cout << "The total amount of the benefit: " << sumCostAllEnergyOrdinary - sumCostEnergy << endl;
			}
			break;

			case 6: {
				fExit = false;
			}
		    break;

			default: {
				cout << "Error. Incorrect input." << endl;
			}
		    break;
		}
		system("pause");
		system("cls");
	} while (fExit);
	for (int i = 0; i < energy.size(); i++) {
		delete energy[i];
	}
	energy.clear();
	return 0;
}

