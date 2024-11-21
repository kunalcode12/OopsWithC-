#include<iostream>
using namespace std;


class complex {
    int a,b;
    public:
        complex(int,int);   //-->>parametrized constructor declaration
        void printnumber(){
            cout<<"the value of a "<<a<<"+"<<b<<"i"<<endl;
        }
};

complex::complex(int x,int y){   // --> this is parametrized constructor as it takes 2 parameters here 
    a=x;
    b=y;
}
int main(){
    // implicit call
    complex h(8,3);   //-->here we dont have to do (h.complex(values,values)) it runs automatically it is constructor
    h.printnumber();

    // explicit call
    complex h1=complex(6,9);
    h1.printnumber();

    return 0;
}