#include<iostream>
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;

public:

    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h,int m,int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getSecond()
    {
        return second;
    }

    void setHour(int h)
    {
        hour = h;
    }

    void setMinute(int m)
    {
        minute = m;
    }

    void setSecond(int s)
    {
        second = s;
    }

    void printTime()
    {
        cout<<hour<<" : "<<minute<<" : "<<second<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter number of Time objects : ";
    cin>>n;


    Time **arr = new Time*[n];

    int choice;
    int index = 0;

    do
    {
        cout<<"\n1.Add Time";
        cout<<"\n2.Display All Time";
        cout<<"\n3.Display only hrs";
        cout<<"\n4.Exit";
        cout<<"\nEnter choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                if(index < n)
                {
                    int h,m,s;

                    cout<<"Enter hour minute second : ";
                    cin>>h>>m>>s;

                    arr[index] = new Time(h,m,s);

                    index++;
                }
                else
                {
                    cout<<"Array Full\n";
                }

                break;
            }

            case 2:
            {
                for(int i=0;i<index;i++)
                {
                    arr[i]->printTime();
                }

                break;
            }

            case 3:
            {
                for(int i=0;i<index;i++)
                {
                    cout<<"Hour : "<<arr[i]->getHour()<<endl;
                }

                break;
            }

            case 4:
                cout<<"Program End\n";
                break;

            default:
                cout<<"Invalid Choice\n";
        }

    }while(choice!=4);

    // Memory Deallocation
    for(int i=0;i<n;i++)
    {
        delete arr[i];
    }

    delete[] arr;

    return 0;
}