#include<iostream>
using namespace std;

/*
syntax for initialization list in constructor:
constructor (argument-list) : initialization-section
{
    assignment + other code;
}
class test{
    int a;
    int b;
    public:
        test(int i,int j):a(i),b(j){    --> here we are initializing the value of a and b directly in constructor
            constructor body
        }
};

*/

class test{
    int a;       //--> this is also the order of declaration
    int b;
    public:
    // testing few cases=
        //test(int i,int j):a(i),b(j)     --> it will work 
        //test(int i,int j):a(i),b(j+i)   --> works
        //test(int i,int j):a(i),b(2*j)   --> works
        //test(int i,int j):a(i),b(a+j)   --> works
        //test(int i,int j):b(j),a(i+b)     --> it will show garbage value of a, reason= as in above private varibles are declared in int a then int b
        test(int i,int j):a(i),b(a+j)     //--> it will work as it is in the order of int a then int b above declared
        {  
            cout<<"constructor executed "<<endl;
            cout<<"the value of a is  "<<a<<endl;
            cout<<"the value of b is  "<<b<<endl;
        }
};
int main(){
    test kunal(2,3);
    return 0;
}