#include <iostream>
using namespace std;

class complex
{
    int a;
    int b;

public:
    void getValue(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    friend complex sumComplex(complex y1, complex y2); // it is an friend function which allows to access the value of private function or variable oustide its class

    void printValue()
    {
        cout << "your number is " << a << " + " << b << "i" << endl;
    }
};

complex sumComplex(complex y1, complex y2)
{
    /*/ it is still not a member function of class complex it is just a outside function with some permissions to access the values
               of class private variables */
    complex y3;
    y3.getValue((y1.a + y2.a), (y1.b + y2.b));
    return y3;
}

int main()
{

    complex c1, c2, sum;
    c1.getValue(3, 4);
    c1.printValue();

    c2.getValue(9, 6);
    c2.printValue();

    sum = sumComplex(c1, c2);
    sum.printValue();

    return 0;
}