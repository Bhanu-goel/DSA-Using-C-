#include<iostream>
using namespace std;

class Operatoroverloading
{
    public:
    void operator+(Operatoroverloading &o)
    { 
        cout<<"hello charlie"<<endl;
    }

    void operator() ()
    {
        cout<<"THis is bracket"<<endl;
    }
};

int main()
{
    Operatoroverloading o1;
    Operatoroverloading o2;
    o1 + o2;
    o1();
}