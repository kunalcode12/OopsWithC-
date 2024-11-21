#include<iostream>
using namespace std;

/*
case1:
Class B:public A{
    first Class A constructor exicuted then Class B
};

case2:
class A:public B,public C{
    order of execution of constructor --> first B() then C() then A()
};

case3:
class A: public B,virtual public C{
    order of execution of constructor --> first C() then B() then A()
}
*/


class base1{
    int data1;
    public:
        base1(int i){
            data1=i;
            cout<<"base1 class constructor is called "<<endl;
        }
        void printdata1(){
            cout<<"the value of data1 is "<<data1<<endl;
        }
};

class base2{
    int data2;
    public:
        base2(int i){
            data2=i;
            cout<<"base2 class constructor is called "<<endl;
        }
        void printdata2(){
            cout<<"the value of data2 is "<<data2<<endl;
        }
};

class derived:public base1,public base2{    // this is also the order the constructor will be executed
    int derived1,derived2;
    public:
        // here is the syntax of giving values to all the constructor inherited here in derived class from base classes in one go
        derived(int a,int b,int c,int d):base1(a),base2(b){
            derived1=c;
            derived2=d;
            cout<<"derived class is called here "<<endl;
        }
        void printdata3(){
            cout<<"the value of derived1 is "<<derived1<<endl;
            cout<<"the value of derived2 is "<<derived2<<endl;
        }
};
int main(){
    derived kunal(1,2,3,4);
    kunal.printdata1();
    kunal.printdata2();
    kunal.printdata3();
    return 0;
}