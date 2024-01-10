#include<iostream>
using namespace std;

class A
{
    public:
    void func()
    {
        cout<<"I am A"<<endl;
    }
};

class B
{
    public:
    void func()
    {
        cout<<"I am B"<<endl;
    }
};

class C : public A,public B
{

};

int main()
{
    C c1;
    // c1.func(); it is ambigous in nature that's why i use global scope operator
    c1.A::func();
    c1.B::func();
    
}