#include<iostream>
using namespace std;

class simple{
    int a,b;
    public:
        simple(int x,int y=8){
            a=x;
            b=y;
        }
        void printdata();

};
void simple::printdata(){
    cout<<"the value is "<<a<<" and "<<b<<endl;
}

int main(){
    simple h(4,9);  
    //simple h(5);  --> if use this then the value at y=8 previously declared will print out
    h.printdata();
    return 0;
}