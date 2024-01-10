#include <bits/stdc++.h> 
using namespace std;
class Rectangle {
    // Write your code here.
    public:
    int length;
    int breadth;

    int getArea()
    {
        return length*breadth;
    }
};

int main()
{
    Rectangle r;
    r.length = 10;
    r.breadth = 20;
    cout<<"Area of rectangle is "<<r.getArea()<<endl;
}