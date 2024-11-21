#include<iostream>
using namespace std;

class base{
    int data1;  // it is private by default and non inheritable
    public:
        int data2;
        void setdata();
        int getdata1();
        int getdata2();
};

void base::setdata(){
    data1=7;
    data2=9;
}
int base::getdata1(){    //--> this function is used to get the inheritable data of base class 
    return data1;
}

int base::getdata2(){
    return data2;
}

class derived : public base{
    int data3;
    public:
        void process();
        void display();
};

void derived::process(){
    data3=data2*getdata1();
}

void derived::display(){
    cout<<"the vale of data1 is "<<getdata1()<<endl;
    cout<<"the vale of data2 is "<<data2<<endl;
    cout<<"the vale of data3 is "<<data3<<endl;
}
int main(){
    derived der;
    der.setdata();
    der.process();
    der.display();
    return 0;
}