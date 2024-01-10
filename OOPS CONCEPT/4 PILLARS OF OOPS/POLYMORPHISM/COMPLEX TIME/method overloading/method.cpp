#include<iostream>
using namespace std;

class Methodoverloading
{
    public:
    void sayhello()
    {
        cout<<"hello I am Human"<<endl;
    }

    void sayhello(string name)
    {
        cout<<"hello I am "<<name<<endl;
    }
};

int main()
{
    Methodoverloading m1;
    m1.sayhello("jk");
}