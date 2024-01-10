#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
    public:

    int r;
    int i;
    ComplexNumbers(int real,int imaginary)
    {
        this->r = real;
        this->i = imaginary;
    }

    void plus(ComplexNumbers &c)
    {
        this->r = this->r + c.r;
        this->i = this->i + c.i;
    }
    
    void multiply(ComplexNumbers &c)
    {
        int a = (this->r * c.r) - (this->i * c.i);
        int b = (this->r * c.i) + (this->i * c.r);
        this->r = a;
        this->i = b;
    }

    void print()
    {
        cout<<r<<" + i"<<i;
    }
    


};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}