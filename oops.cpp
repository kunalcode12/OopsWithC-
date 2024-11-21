#include<iostream>
using namespace std;

class employee
{
    private:
        int a,b,c;

    public:
        int d,e;
        void setData(int a1,int b1,int c1);   // it is just fuction declaration whic we can call either inside the class or outside the class 
        void getData(){
            cout<<"the value of a is "<<a<<endl;   // it is a example of calling a function inside a class 
            cout<<"the value of b is "<<b<<endl;
            cout<<"the value of c is "<<c<<endl;
            cout<<"the value of d is "<<d<<endl;
            cout<<"the value of e is "<<e<<endl;

        }
};

void employee :: setData(int a1,int b1,int c1){    // it is a way of calling a fuction outside a class
    a=a1;
    b=b1;
    c=c1;
}

int main(){
    employee kunal;
    //kunal.a=6;   // here we cannot give values to a as it is in private class
    kunal.d=78;
    kunal.e=65;
    kunal.setData(2,8,9);
    kunal.getData();

    return 0;
}