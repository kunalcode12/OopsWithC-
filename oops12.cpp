#include<iostream>
using namespace std;

class complex{
    int a,b;
    public:
         complex(void);   // constructor declaration
         void printnumber(){
            cout<<"the value of "<<a<<"+"<<b<<"i"<<endl;
         }

};

complex::complex(void){    // this is default constructor
    //cout<<"enter value of a "<<endl;  // it can also be used to get the value
    //cin>>a;
    a=10;
    b=20;
}

int main(){
    complex h;
    h.printnumber();
    
    return 0;
}