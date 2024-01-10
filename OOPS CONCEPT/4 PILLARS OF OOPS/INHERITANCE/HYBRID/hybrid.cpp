#include<iostream>
using namespace std;

class A
{
    public:
    void func1()
    {
        cout<<"inside func 1"<<endl;
    }
};

class B : public A
{
    public:
    void func2()
    {
        cout<<"inside func 2"<<endl;
    }
};

class C : public A
{
    public:
    void func3()
    {
        cout<<"inside func 3"<<endl;
    }
};

class D : public C
{
    public:
    void func4()
    {
        cout<<"inside func 4"<<endl;
    }
};

int main()
{
    D d1;
    d1.func1();
    d1.func3();
    d1.func4();
}