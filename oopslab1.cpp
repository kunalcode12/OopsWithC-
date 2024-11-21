#include <iostream>
using namespace std;

class complex;

class calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumRealComplex(complex, complex);
    int sumCompComplex(complex,complex);
};

class complex
{
    int a;
    int b;
                  // individually declaring function as friends
    //friend int calculator::sumRealComplex(complex, complex);
    //friend int calculator::sumCompComplex(complex, complex);

        // alternative = as if there is too much number of function to call in another class then we can declare a whole class as a friend
    friend class calculator;

public:
    void getValue(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    void printValue()
    {
        cout << "your number is " << a << " + " << b << "i" << endl;
    }
};

int calculator ::sumRealComplex(complex x1, complex x2)
{
    return (x1.a + x2.a);
}

int calculator ::sumCompComplex(complex x1, complex x2)
{
    return (x1.b + x2.b);
}


int main()
{
    complex z1, z2;
    z1.getValue(1, 3);
    z1.printValue();

    z2.getValue(6, 8);
    z2.printValue();

    calculator calc;
    int res = calc.sumRealComplex(z1, z2);
    cout << "the sum of numbers is " << res << endl;

    int resc = calc.sumCompComplex(z1, z2);
    cout << "the sum of complex numbers is " << resc << endl;


    return 0;
}