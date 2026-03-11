#include <iostream>
using namespace std;

class Box {
    float l, w, h;

public:
    // Default constructor
    Box() {
        l = 1;
        w = 1;
        h = 1;
    }

    // Single parameter constructor
    Box(float x) {
        l = w = h = x;
    }

    // Three parameter constructor
    Box(float a, float b, float c) {
        l = a;
        w = b;
        h = c;
    }

    void displayVolume() {
        cout << "Volume = " << l * w * h << endl;
    }
};

int main() {
    int ch;
    float a, b, c, x;

    cout << "1. Default values\n";
    cout << "2. Same length, width, height\n";
    cout << "3. Different length, width, height\n";
    cout << "Enter choice: ";
    cin >> ch;

    switch(ch) {
        case 1: {
            Box b1;
            b1.displayVolume();
            break;
        }

        case 2: {
            cout << "Enter value: ";
            cin >> x;
            Box b2(x);
            b2.displayVolume();
            break;
        }

        case 3: {
            cout << "Enter length width height: ";
            cin >> a >> b >> c;
            Box b3(a,b,c);
            b3.displayVolume();
            break;
        }

        default:
            cout << "Invalid choice";
    }

    return 0;
}