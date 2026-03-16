#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int id;
    string title;
    float price;

public:
    Product(int i, string t, float p) : id(i), title(t), price(p) {}
    virtual ~Product() {}
    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
    virtual float getFinalPrice() { return price; }
};

class Book : public Product {
protected:
    string author;
public:
    Book(int i, string t, string a, float p) : Product(i, t, p), author(a) {}
    float getFinalPrice() override { return price * 0.90; }
    void display() override {
        Product::display();
        cout << "Author: " << author << endl;
        cout << "Final Price: " << getFinalPrice() << endl;
    }
};

class Tape : public Product {
protected:
    string artist;
public:
    Tape(int i, string t, string a, float p) : Product(i, t, p), artist(a) {}
    float getFinalPrice() override { return price * 0.95; }
    void display() override {
        Product::display();
        cout << "Artist: " << artist << endl;
        cout << "Final Price: " << getFinalPrice() << endl;
    }
};

int main() {
    Product* arr[3];
    int id;
    float price, totalBill = 0;
    string title, author, artist;

    cout << "=== Shop ===\n";

    
    cout << "\nEnter details for Book 1:\n";
    cout << "Enter ID: "; cin >> id; cin.ignore();
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Author: "; getline(cin, author);
    cout << "Enter Price: "; cin >> price;
    arr[0] = new Book(id, title, author, price);

    
    cout << "\nEnter details for Book 2:\n";
    cout << "Enter ID: "; cin >> id; cin.ignore();
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Author: "; getline(cin, author);
    cout << "Enter Price: "; cin >> price;
    arr[1] = new Book(id, title, author, price);

    
    cout << "\nEnter details for Tape:\n";
    cout << "Enter ID: "; cin >> id; cin.ignore();
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Artist: "; getline(cin, artist);
    cout << "Enter Price: "; cin >> price;
    arr[2] = new Tape(id, title, artist, price);

    cout << "\n=== Your Bill ===\n";
    for (int i = 0; i < 3; i++) {
        arr[i]->display();
        totalBill += arr[i]->getFinalPrice();
        delete arr[i];
    }

    cout << "\nTotal amount to pay: " << totalBill << endl;
    return 0;
}