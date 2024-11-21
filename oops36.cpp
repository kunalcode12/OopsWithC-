#include<iostream>
using namespace std;

class baseclass{
    public:
        int varbase=2;
        virtual void display(){  /* here virtual is used to tell the compiler if my type of pointer is pointing towards derived class object so 
                                   run derived class display() not mine */
            cout<<"displaying base class variable varbase "<<varbase<<endl;
        }
};
class derivedclass:public baseclass{
    public:
    int varderived=3;
    void display(){
        cout<<"displaying base class variable varbase "<<varbase<<endl;
        cout<<"displaying derived class variable varderived "<<varderived<<endl;
    }
};

int main(){
    baseclass*baseclasspointer;
    baseclass objbase;
    derivedclass objderived;

    baseclasspointer=&objderived;
    baseclasspointer->display();  /*it is a default behaviour of base class pointer it will only run its display function even after pointing 
                                    it to  derived class object if we dont use virtual function */
    
    return 0;
}