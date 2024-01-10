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

class GermanShephard : public dog
{

};

int main()
{
    GermanShephard g1;
    cout<<g1.age<<endl;
    g1.speak();
}