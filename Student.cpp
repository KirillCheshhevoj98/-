#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	string faculity;
protected:	
	int course;
	int minimumScore;

public:

	Student()
	{
		name = "None";
		faculity = "None";
		course = 0;
		minimumScore = 0;
	}

	Student(string name, string faculity, int course, int minimumScore)
	{
		this->name = name;
		this->faculity = faculity;
		this->course = course;
		this->minimumScore = minimumScore;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void setFaculity(string faculity)
	{
		this->faculity = faculity;
	}

	string getFaculity()
	{
		return faculity;
	}

	void setCourse(int course)
	{
		this->course = course;
	}

	int getCourse()
	{
		return course;
	}

	void setMinimumScore()
	{
		if (minimumScore > 0 && minimumScore < 6)
		{
			this->minimumScore = minimumScore;
		}
		else
		{
			this->minimumScore = 0;
		}
	}

	int getMinimumScore()
	{
		return minimumScore;
	}

	void TransferNextCourse(int minimumScore)
	{
		if (minimumScore >= 3)
		{
			 cout << "Your new course";
			 course += 1;
		}
	}

	int Stipend()
	{
		if (this->minimumScore <= 3)
		{
			return 0;
		}
		else
		{
			if (this->minimumScore == 4)
			{
				return 30;
			}
			else
			{
				return 50;
			}
		}
	}

	void InfoStudent()
	{
		cout << "Name: " << name << endl
			<< "Faculity: " << faculity << endl
			<< "Course: " << course << endl
			<< "Minimum score to the exam: " << minimumScore << endl
			<< "Stipend: " << Stipend() << endl;
	}
	
	~Student()
	{
	}
};

class StudentContract : public Student
{
private:
	bool paidCourse;
public:
	StudentContract()
	{
		paidCourse = false;
	}

	StudentContract(string name, string faculity, int course, int minimumScore, bool paidCourse) : Student(name, faculity, course, minimumScore)
	{
		this->paidCourse = paidCourse;
	}

	void setPaidCourse(bool paidCourse)
	{
		this->paidCourse = paidCourse;
	}

	bool getPaidCourse()
	{
		return paidCourse;
	}

	void TransferNextCourse(int minimumScore)
	{
		if (minimumScore >= 3 && paidCourse == true)
		{
			cout << "Your new course";
			this->course += 1;
		}
	}

	int Stipend()
	{
		return 0;
	}

	void InfoStudent()
	{
		cout << "Name: " << getName() << endl
			<< "Faculity: " << getFaculity() << endl
			<< "Course: " << getCourse() << endl
			<< "Minimum score to the exam: " << getMinimumScore() << endl
			<< "Paid to the course: " << paidCourse << endl
			<< "Stipend: " << Stipend() << endl;
	}

	~StudentContract()
	{
	}
};
int main()
{
	Student* st1 = new Student("Ivan Ivanov", "History", 1, 1);
	st1->TransferNextCourse(1);
	st1->InfoStudent();
	delete st1;
	st1 = NULL;

	cout << "---------------------------" << endl;
	Student* st2 = new Student("Petrov Petrov", "Mathimatic", 2, 4);
	st2->TransferNextCourse(4);
	st2->InfoStudent();
	delete st2;
	st2 = NULL;

	cout << "---------------------------" << endl;
	StudentContract* stcon1 = new StudentContract("Petrov Petrov", "Mathimatic", 1, 4, false);
	stcon1->TransferNextCourse(4);
	stcon1->InfoStudent();
	delete stcon1;
	stcon1 = NULL;

	cout << "---------------------------" << endl;
	StudentContract* stcon2 = new StudentContract("Petrov Petrov", "Mathimatic", 1, 5, true);
	stcon2->TransferNextCourse(5);
	stcon2->InfoStudent();
	delete stcon2;
	stcon2 = NULL;

	system("pause");
	return 0;
}