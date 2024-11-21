#include<iostream>
using namespace std;

class A{
    int a;
    public:
        A& setdata(int a ){  // this is local variable
            //a=a;    // here this will show error as in c++ we give priority to local variable 
            this->a=a;     // here we use (this->) pointer to verify which a we are talking about
            return*this;
        }
        void getdata(){
            cout<<"the value of a is "<<a<<endl;
        }
};
int main(){
    A a;
    a.setdata(7).getdata(); // here after using A& it is returning object which is same like (A a;) above so we can use it like before as you can see
    //a.getdata();
    return 0;
}