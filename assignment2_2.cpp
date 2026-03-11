#include<iostream>
using namespace std;

class tollbooth
{
private:
    unsigned int totalCars;
    unsigned int payingCars;
    unsigned int nonPayingCars;
    double totalCash;

public:
    
    tollbooth()
    {
        totalCars = 0;
        payingCars = 0;
        nonPayingCars = 0;
        totalCash = 0.0;
    }

    
    void payingCar()
    {
        totalCars++;
        payingCars++;
        totalCash += 0.50;
    }

    
    void nopayCar()
    {
        totalCars++;
        nonPayingCars++;
    }

    void printOnConsole()
    {
        cout << "Total Cars: " << totalCars << endl;
        cout << "Paying Cars: " << payingCars << endl;
        cout << "Non Paying Cars: " << nonPayingCars << endl;
        cout << "Total Cash Collected: $" << totalCash << endl;
    }
};

int main()
{
    tollbooth t;

    t.payingCar();
    t.payingCar();
    t.nopayCar();
    t.payingCar();
    t.nopayCar();

    t.printOnConsole();

    return 0;
}