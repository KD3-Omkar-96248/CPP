#include<iostream>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;
    static double PI;

public:

    
    Cylinder() : radius(0), height(0)
    {
    }

    
    Cylinder(double radius, double height) : radius(radius), height(height)
    {
    }

    
    double getRadius()
    {
        return radius;
    }

    
    void setRadius(double radius)
    {
        this->radius = radius;
    }


    double getHeight()
    {
        return height;
    }


    void setHeight(double height)
    {
        this->height = height;
    }

    
    double calculateVolume()
    {
        return PI * radius * radius * height;
    }
};

double Cylinder::PI = 3.14;

int main()
{
    Cylinder c1(3,7);

    cout<<"Radius : "<<c1.getRadius()<<endl;
    cout<<"Height : "<<c1.getHeight()<<endl;

    cout<<"Volume of Cylinder = "<<c1.calculateVolume()<<endl;

    return 0;
}