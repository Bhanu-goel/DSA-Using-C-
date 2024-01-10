#include<iostream>
using namespace std;

class Animal
{
    public:
    int age;
    int weight;

    void speak()
    {
        cout<<"speaking"<<endl;
    }
};

class dog: public Animal
{

};

int main()
{
    dog d1;
    cout<<d1.age<<endl;
    d1.speak();
}