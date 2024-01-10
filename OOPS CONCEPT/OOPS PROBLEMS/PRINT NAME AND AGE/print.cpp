#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class Person {

    // Complete the class
    public:

    string name;
    int age;

    string getname()
    {
        return name;
    }

    int getage()
    {
        return age;
    }

    void setname(string n)
    {
        name = n;
    }

    void setage(int a)
    {
        age = a;
    }

};

int main() {

    //Write your code here
    int age;
    string name;
    cin>>name;
    cin>>age;
    Person p;
    p.setname(name);
    p.setage(age);
    cout<<"The name of the person is "<<p.getname()<<" and the age is "<<p.getage()<<"."<<endl;
    

    return 0;
}