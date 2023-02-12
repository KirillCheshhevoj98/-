#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include <iostream>

struct MyTriangle {
private:
	int a;
	int b;
	int c;

public:
	MyTriangle() {
		this->a = 3;
		this->b = 4;
		this->c = 5;
	}

	MyTriangle(int a, int b, int c) {
		this->setA(a);
		this->setB(b);
		this->setC(c);
	}

	void setA(int a) {
		if (0 < a) {
			this->a = a;
		}
		else {
			this->a = 0;
		}
	}

	void setB(int b) {
		if (0 < b) {
			this->b = b;
		}
		else {
			this->b = 0;
		}
	}

	void setC(int c) {
		if (0 < c) {
			this->c = c;
		}
		else {
			this->c = 0;
		}
	}

	int getA() {
		return this->a;
	}

	int getB() {
		return this->b;
	}

	int getC() {
		return this->c;
	}

	int Perimeter() {
		int perimeter;
		perimeter = this->a + this->b + this->c;
		return perimeter;
	}

	double Square() {
		double square, p;
		p = Perimeter() / 2;
		square = sqrt(p * (p - a) * (p - b) * (p - c));
		return square;
	}

	void Info() {
		printf("Triangle with sides: %d, %d, %d\n", this->a, this->b, this->c);
		printf("Perimeter: %d\n", Perimeter());
		printf("Square: %.2lf\n", Square());
	}

	bool IsTriangle(int a, int b, int c) {
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			return true;
		}
		return false;
	}

	~MyTriangle() {
		printf("Working destructor\n");
	}
};

int main() {
	MyTriangle triangle1;

	triangle1.Info();

	MyTriangle triangle2;
	int side_1, side_2, side_3;

	printf("Enter value of side 1:");
	scanf("%d", &side_1);
	printf("Enter value of side 2:");
	scanf("%d", &side_2);
	printf("Enter value of side 3:");
	scanf("%d", &side_3);


	if (triangle2.IsTriangle(side_1, side_2, side_3) == true) {
		triangle2.setA(side_1);
		triangle2.setB(side_2);
		triangle2.setC(side_3);
		triangle2.Info();
	}
	else {
		printf("Error\n");
	}
	getchar();
	return 0;
}