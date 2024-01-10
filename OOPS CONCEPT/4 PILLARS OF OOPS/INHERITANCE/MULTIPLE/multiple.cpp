#include<iostream>
using namespace std;

class Animal
{
    public:
    int age;
    int weight;

    void bark()
    {
        cout<<"barking"<<endl;
    }
};

class Human
{
    public:
    string color;

    void speak()
    {
        cout<<"speaking"<<endl;
    }
};

class hybrid : public Animal,public Human
{

};

int main()
{
    hybrid h1;
    cout<<h1.age<<endl;
    h1.bark();
    h1.speak();
}