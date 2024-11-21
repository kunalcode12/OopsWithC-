#include<iostream>
using namespace std;

class complex{
    int real,imaginary;
    public:
        void getdata(){
            cout<<"the real part is "<<real<<endl;
            cout<<"the imaginary part is "<<imaginary<<endl;
        }
        void setdata(int a,int b){
            real=a;
            imaginary=b;
        }
};

int main(){
    // below method can also we used
    //complex c1;
    //complex*ptr=&c1;

    complex*ptr=new complex;    //--> this will also work
    //(*ptr).setdata(7,8);    --> it is exactly same as below 
    ptr->setdata(7,8);

    //(*ptr).getdata();  --> is exactly as good as below
    ptr->getdata();

    // Array of objects

    complex*ptr1=new complex[4];    //--> this will also work
    //(*ptr).setdata(7,8);    --> it is exactly same as below 
    ptr1->setdata(3,2);

    //(*ptr).getdata();  --> is exactly as good as below
    ptr1->getdata();          // Arrow operator (->) is more efficient to use
    return 0;
}