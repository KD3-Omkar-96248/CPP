#include <iostream>
using namespace std;

class Employee
{
protected:
    int id;
    double salary;

public:
    Employee()
    {
        id = 0;
        salary = 0;
    }

    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return salary;
    }

    virtual void accept()
    {
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : virtual public Employee
{
protected:
    double bonus;

public:
    Manager()
    {
        bonus = 0;
    }

    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }

    void acceptManager()
    {
        accept();
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void displayManager()
    {
        display();
        cout << "Bonus: " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{
protected:
    double commission;

public:
    Salesman()
    {
        commission = 0;
    }

    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return commission;
    }

    void acceptSalesman()
    {
        accept();
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void displaySalesman()
    {
        display();
        cout << "Commission: " << commission << endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }

    SalesManager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission)
    {
    }

    void accept()
    {
        Employee::accept();

        cout << "Enter Bonus: ";
        cin >> bonus;

        cout << "Enter Commission: ";
        cin >> commission;
    }

    void display()
    {
        Employee::display();
        cout << "Bonus: " << bonus << endl;
        cout << "Commission: " << commission << endl;
    }
};

int main()
{
    SalesManager sm;

    sm.accept();
    cout << endl;

    cout << "Sales Manager Details:" << endl;
    sm.display();

    return 0;
}