#include<iostream>
using namespace std;

class number{
    int a;
    public:
        number(){      //-->blank constructor
            a=0;       //-->here we declared default value of a=0
        }   
        number(int num){
            a=num;
        }

        // when there is no copy constructor is found then compiler supply its own copy constructor
        number(number &obj){     //--> copy constructor
            cout<<"copy constructor called !!! "<<endl;
            a=obj.a;
        }
        void display(){
            cout<<"the number of this object is "<<a<<endl;
        }
};

int main(){
    number h1,h2,h3(6),h4;
    h1.display();
    h2.display();
    h3.display();
    number z1(h3);
    z1.display();

    h4=h3;    //-->copy constructor is not called becouse h4 is already an object which we declared above but if it has been done like z1 then it will work
    number z2=h3; //--> here copy constructor will work as the object has been made here
    return 0;
} 