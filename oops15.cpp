#include<iostream>
using namespace std;

class complex{
    int a,b;
    public:
        complex(){   //--> it is an default constructor
            a=0;
            b=0;
        }
        complex(int x,int y){   //--> both here ar parametrized constructor
            a=x;
            b=y;
        }

        complex(int x){
            a=x;
            b=0;
        }
        void printdata(){
            cout<<"the value is "<<a<<"+"<<b<<"i"<<endl;
        }
};

int main(){
    complex h(7,8);
    h.printdata();

    complex h1(7);
    h1.printdata();

    complex h3;     //--> no arguments given as it is default constructor
    h3.printdata();

    return 0;
}