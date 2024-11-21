#include<iostream>
using namespace std;

class baseclass{
    public:
        int varbase;
        void display(){
            cout<<"displaying base class variable varbase "<<varbase<<endl;
        }
};
class derivedclass:public baseclass{
    public:
    int varderived;
    void display(){
        cout<<"displaying base class variable varbase "<<varbase<<endl;
        cout<<"displaying derived class variable varderived "<<varderived<<endl;
    }
};

int main(){
    baseclass*baseclasspointer;  // it is a pointer which will point at object of base class
    baseclass objbase;
    derivedclass objderived;
    baseclasspointer=&objderived;   // base class pointer pointing to derived class object

    baseclasspointer->varbase=8;  // we can give value like this as it is public variable
    //baseclasspointer->varderived=7;     //this will throw arror as base class pointer cannot asses derived class properties
    baseclasspointer->display();

    baseclasspointer->varbase=86;  // we can also change the values
    baseclasspointer->display();

    // now using derived class pointer
    derivedclass*derivedclasspointer;  // derived class pointer can asses base class variables and function
    derivedclasspointer=&objderived;
    derivedclasspointer->varderived=7;
    derivedclasspointer->varbase=67;
    derivedclasspointer->display();

    // above here:
    // we are choosing which function to run and giving it its value which is run time polymorphism


    return 0;
}