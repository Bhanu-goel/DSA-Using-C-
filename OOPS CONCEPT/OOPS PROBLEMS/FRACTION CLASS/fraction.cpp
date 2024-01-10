#include <bits/stdc++.h> 
#include<iostream>

#include<algorithm>
using namespace std;

class Fraction {
    public:
    int num;
    int denom;
    // Complete the class
    Fraction(int n,int d)
    {
        num = n;
        denom = d;
    }

    void add(Fraction &f)
    {
        int d = this->denom * f.denom;
        int n = (this->num*f.denom)+(this->denom*f.num);
        this->num = n;
        this->denom=d;
    }

    void multiply(Fraction &f)
    {
        int d = this->denom * f.denom;
        int n =this->num * f.num;
        this->num = n;
        this->denom = d;
    }

    void simplify()
    {
        int gcd = __gcd(this->num,this->denom);
        this->num = this->num/gcd;
        this->denom = this->denom/gcd;
    }

    void print()
    {
        cout<<num<<"/"<<denom<<endl;
    }
};

int main() 
{
    //Write your code here
    int n1,d1,n2,d2,query,choice;
    cin>>n1>>d1;

    Fraction f1(n1,d1);
    cin>>query;
    
    while(query>0)
    {
        cin>>choice>>n2>>d2;
        Fraction f2(n2,d2);
        if(choice ==1)
        {
            f1.add(f2);
            f1.simplify();
            f1.print();
        }

        if(choice ==2)
        {
            f1.multiply(f2);
            f1.simplify();
            f1.print();
        }
        query--;

    }
    return 0;
}