#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void initDate()
    {
        day = 1;
        month = 1;
        year = 2000;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter Day: ";
        cin >> day;

        cout << "Enter Month: ";
        cin >> month;

        cout << "Enter Year: ";
        cin >> year;
    }

    void printDateOnConsole()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    bool isLeapYear()
    {
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Date d;

    d.acceptDateFromConsole();
    d.printDateOnConsole();

    if(d.isLeapYear())
        cout << "Leap Year" << endl;
    else
        cout << "Not a Leap Year" << endl;

    return 0;
}