#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    void acceptDate()
    {
        cout << "Enter Day Month Year: ";
        cin >> day >> month >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year;
    }
};

class Person
{
private:
    string name;
    string address;
    Date birthdate;   // Association

public:
    void acceptPerson()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Address: ";
        cin >> address;

        cout << "Enter Birthdate\n";
        birthdate.acceptDate();
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthdate.displayDate();
        cout << endl;
    }
};

class Student
{
private:
    int id;
    float marks;
    string course;
    Date joiningDate;  // Association
    Date endDate;      // Association

public:
    void acceptStudent()
    {
        cout << "Enter Student ID: ";
        cin >> id;

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "Enter Course: ";
        cin >> course;

        cout << "Enter Joining Date\n";
        joiningDate.acceptDate();

        cout << "Enter End Date\n";
        endDate.acceptDate();
    }

    void displayStudent()
    {
        cout << "Student ID: " << id << endl;
        cout << "Marks: " << marks << endl;
        cout << "Course: " << course << endl;

        cout << "Joining Date: ";
        joiningDate.displayDate();
        cout << endl;

        cout << "End Date: ";
        endDate.displayDate();
        cout << endl;
    }
};

int main()
{
    Person p;
    Student s;

    cout << "\nEnter Person Details\n";
    p.acceptPerson();

    cout << "\nEnter Student Details\n";
    s.acceptStudent();

    cout << "\nPerson Details\n";
    p.displayPerson();

    cout << "\nStudent Details\n";
    s.displayStudent();

    return 0;
}