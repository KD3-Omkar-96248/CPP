#include <iostream>
#include <vector>
using namespace std;


class Employee {
protected:
    int id;
    double salary;

public:
    Employee() {
        id = 0;
        salary = 0;
    }

    Employee(int id, double salary) {
        this->id = id;
        this->salary = salary;
    }

    virtual void accept() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display() {
        cout << "ID: " << id << ", Salary: " << salary;
    }

    virtual ~Employee() {}
};


class Manager : virtual public Employee {
protected:
    double bonus;

public:
    Manager() {
        bonus = 0;
    }

    void accept() {
        Employee::accept();
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void display() {
        Employee::display();
        cout << ", Bonus: " << bonus;
    }
};


class Salesman : virtual public Employee {
protected:
    double commission;

public:
    Salesman() {
        commission = 0;
    }

    void accept() {
        Employee::accept();
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void display() {
        Employee::display();
        cout << ", Commission: " << commission;
    }
};


class SalesManager : public Manager, public Salesman {
public:
    SalesManager() {}

    void accept() {
        Employee::accept();
        cout << "Enter Bonus: ";
        cin >> bonus;
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void display() {
        Employee::display();
        cout << ", Bonus: " << bonus
             << ", Commission: " << commission;
    }
};


int menu() {
    int choice;
    cout << "\n---- MENU ----\n";
    cout << "1. Add Manager\n";
    cout << "2. Add Salesman\n";
    cout << "3. Add SalesManager\n";
    cout << "4. Display Count\n";
    cout << "5. Display Managers\n";
    cout << "6. Display Salesmen\n";
    cout << "7. Display SalesManagers\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}


int main() {
    vector<Employee*> empList;
    int choice;

    do {
        choice = menu();

        switch (choice) {
        case 1: {
            Employee* e = new Manager();
            e->accept();
            empList.push_back(e);
            break;
        }

        case 2: {
            Employee* e = new Salesman();
            e->accept();
            empList.push_back(e);
            break;
        }

        case 3: {
            Employee* e = new SalesManager();
            e->accept();
            empList.push_back(e);
            break;
        }

        case 4: {
            int m = 0, s = 0, sm = 0;
            for (auto e : empList) {
                if (dynamic_cast<Manager*>(e) && !dynamic_cast<SalesManager*>(e))
                    m++;
                else if (dynamic_cast<Salesman*>(e) && !dynamic_cast<SalesManager*>(e))
                    s++;
                else if (dynamic_cast<SalesManager*>(e))
                    sm++;
            }
            cout << "Managers: " << m << endl;
            cout << "Salesmen: " << s << endl;
            cout << "SalesManagers: " << sm << endl;
            break;
        }

        case 5:
            for (auto e : empList) {
                if (dynamic_cast<Manager*>(e) && !dynamic_cast<SalesManager*>(e)) {
                    e->display();
                    cout << endl;
                }
            }
            break;

        case 6:
            for (auto e : empList) {
                if (dynamic_cast<Salesman*>(e) && !dynamic_cast<SalesManager*>(e)) {
                    e->display();
                    cout << endl;
                }
            }
            break;

        case 7:
            for (auto e : empList) {
                if (dynamic_cast<SalesManager*>(e)) {
                    e->display();
                    cout << endl;
                }
            }
            break;

        }

    } while (choice != 0);


    for (auto e : empList)
        delete e;

    return 0;
}