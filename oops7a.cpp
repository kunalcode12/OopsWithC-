#include<iostream>
using namespace std;

class complex{
    int a;
    int b;

    public:
        void setData(int v1,int v2){    // while using below code this int v1,int v2 should be removed and void can be used in it
            //cout<<"enter the value of a "<<endl;    <--// this can also be used
            //cin>>a;
            //cout<<"enter the value of b "<<endl;
            //cin>>b;
            a=v1;                               //<-- this is used so we can assign value by ourselves
            b=v2;
        }

        void sumData(complex x1, complex x2){
            a=x1.a +x2.a;
            b=x1.b +x2.b;

        }
        void printData(){
            cout<<" complex numbers is "<<a<<"+"<<"i"<<b<<endl;
        }

};

int main(){
    complex h1,h2,h3;
    h1.setData(7,8);
    h1.printData();

    h2.setData(9,5);
    h2.printData();

    h3.sumData(h1,h2);
    h3.printData();
    
    return 0;
}