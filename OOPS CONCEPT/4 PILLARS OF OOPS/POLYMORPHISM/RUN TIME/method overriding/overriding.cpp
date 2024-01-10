#include<iostream>
using namespace std;

class Animal
{
    public:
    void speak()
    {
        cout<<"speaking"<<endl;
    }
};

class dog : public Animal
{
    public:
    void speak()
    {
        cout<<"barking"<<endl;
    }
};

int main()
{
    dog d1;
    d1.speak();
}