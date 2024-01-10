#include<iostream>
#include"Hero.cpp"
using namespace std;
#include<string.h>
#include<algorithm>
class hero
{
    private:
    int health;
    public:
    char level;
    char name[100];
    static int timetocomplete;
    void print()
    {
        cout<<name<<endl;
    }

    int gethealth()
    {
        return health;
    }

    char getlevel()
    {
        return level;
    }

    void sethealth(int h)
    {
        health = h;
    }

    void setlevel(char l)
    {
        level = l;
    }

    void setname(char name[])
    {
        strcpy(this->name,name);
    }
    //default constructor
    hero()
    {
    cout<<"constructor called"<<endl;
    }

    //parameterized constructor
    hero(int health)
    {
        this->health=health;
    }

    hero (hero &temp)
    {
        this->health = temp.health;
        this->level = temp.level;
        strcpy(this->name,temp.name);
    }

    ~hero()
    {
        cout<<"destructor called"<<endl;
    }
};

int hero::timetocomplete = 5;

int main()
{
    hero ramesh;

    //hero *h = new hero;
    // //ramesh.health = 70;
    // //ramesh.level = 'A';
    // // Hero h1;
    // // cout<<sizeof(ramesh)<<endl;
    // // cout<<ramesh.health<<endl;
    // // cout<<ramesh.level<<endl;

    // // cout<<ramesh.gethealth()<<endl;
    // // cout<<ramesh.getlevel()<<endl;

    ramesh.sethealth(100);
    ramesh.setlevel('A');
    char name[6] = "bhanu"; 
    ramesh.setname(name);
    // // cout<<ramesh.gethealth()<<endl;
    // // cout<<ramesh.getlevel()<<endl;

    // cout<<ramesh.level<<endl;
    // cout<<ramesh.gethealth()<<endl;

    // // cout<<(*h).level<<endl;
    // // cout<<(*h).gethealth()<<endl;

    // cout<<h->level<<endl;
    // cout<<h->gethealth()<<endl;

    // hero ramesh1(50);
    // cout<<ramesh1.gethealth()<<endl;

    hero s(ramesh);
    cout<<s.gethealth()<<endl;
    cout<<s.getlevel()<<endl;
    cout<<s.name<<endl;
    cout<<ramesh.name<<endl; 

    ramesh.name[0]='D';
    ramesh.print();
    s.print();

    
    cout<<hero::timetocomplete<<endl;

    return 0;
}