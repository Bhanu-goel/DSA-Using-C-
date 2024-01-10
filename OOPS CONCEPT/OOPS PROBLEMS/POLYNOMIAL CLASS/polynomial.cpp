#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class Polynomial {
    
    public:
    int * degCoeff; // Name of your array (Don't change this)
    int size;
    //default constructor
    Polynomial()
    {
        degCoeff = new int[1000];
        for(int i=0;i<1000;i++)
        {
            degCoeff[i]=0;
        }
        size = 1000;
    }

    //copy constructor
    Polynomial(Polynomial &temp)
    {
        degCoeff = new int[temp.size];
        for(int i=0;i<temp.size;i++)
        {
            degCoeff[i] = temp.degCoeff[i];
        }
        size = temp.size;
    }

    //set Coefficient
    void setCoefficient(int ind,int coef)
    {
        if(ind>=size)
        {
            int *newdegcoeff = new int[ind];
            for(int i=0;i<size;i++)
            {
                newdegcoeff[i] = degCoeff[i];
            }

            for(int i=size;i<ind;i++)
            {
                newdegcoeff[i]=0;
            }
            delete[] degCoeff;
            degCoeff = newdegcoeff;
            size = ind;
        }
        degCoeff[ind] = coef;
    }

    //overload + operator
    Polynomial operator+ (Polynomial &p)
    {
        Polynomial res;
        res.size = max(size,p.size);
        res.degCoeff = new int[res.size];

        if(size<p.size)
        {
            int i;
            for(int i=0;i<size;i++)
        {
            res.degCoeff[i]=degCoeff[i]+p.degCoeff[i];
        }
        for(;i<p.size;i++)
        {
            res.degCoeff[i] = p.degCoeff[i];
        }
        }
        else
        {
            int i;
            for(i=0;i<size;i++)
        {
            res.degCoeff[i]=degCoeff[i]+p.degCoeff[i];
        }
        for(;i<p.size;i++)
        {
            res.degCoeff[i] = degCoeff[i];
        }
        }
        
        return res;
    }

    Polynomial operator- (Polynomial &p)
    {
        Polynomial res;
        res.size = max(size,p.size);
        res.degCoeff = new int[res.size];

        if(size<p.size)
        {
            int i;
            for(i=0;i<size;i++)
        {
            res.degCoeff[i]=degCoeff[i]-p.degCoeff[i];
        }
        for(;i<p.size;i++)
        {
            res.degCoeff[i] = -p.degCoeff[i];
        }
        }
        else
        {
            int i;
            for(i=0;i<size;i++)
        {
            res.degCoeff[i]=degCoeff[i]-p.degCoeff[i];
        }
        for(;i<p.size;i++)
        {
            res.degCoeff[i] = degCoeff[i];
        }
        }
        
        return res;
    }

    Polynomial operator* (Polynomial &p)
    {
        Polynomial res;
        res.size = size+p.size;
        res.degCoeff = new int[res.size];
        for(int i=0;i<res.size;i++)
        {
            res.degCoeff[i]=0;
        }

        for(int i=0;i<size;i++)
        {
            
                for(int j=0;j<p.size;j++)
                    {
                        res.degCoeff[i+j] += (degCoeff[i]*p.degCoeff[j]);
                    }       
        }
        return res;
    }
    Polynomial operator= (const Polynomial &p)
    {
         if (this != &p) {
            delete[] degCoeff;
            size = p.size;
            degCoeff = new int[size];
            for (int i = 0; i < size; i++)
                degCoeff[i] = p.degCoeff[i];
        }
        return *this;
    }
    void print()
    {
        for(int i=0;i<size;i++)
        {
            if(degCoeff[i]!=0)
            {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
    }
    // Complete the class

};

int main() {
    int count1, count2, choice;
    cin >> count1;

    int * degree1 = new int[count1];
    int * coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }
    
    cin >> count2;

    int * degree2 = new int[count2];
    int * coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice) {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    }

    return 0;
}