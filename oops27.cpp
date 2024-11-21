// ambiguity resolution
#include<iostream>
using namespace std;

class base1{
    public:
        void greet(){
            cout<<"uwu"<<endl;
        }
};

class base2{
    public:
        void greet(){
            cout<<"no uwu"<<endl;
        }
};

class derived : public base1,public base2{
    int d;
    public:
        void greet(){
            base1::greet();    // it is here to solve ambiguity error without this compiler will get confused between choosing same name function 
        }
};

class d{
    public:
        void say(){
            cout<<"hello"<<endl;
        }
};

class e:public d{
    int a;
    /*
    it will not not show ambiguity
    as e's new say() wil overwrite base class's say() method
    */
    public:
        void say(){
            cout<<"bye"<<endl;
        }
};

int main(){
    //Ambiguity 1:

    //base1 base1obj;
    //base2 base2obj;
    //base1obj.greet();
    //base2obj.greet();
    //derived d;
    //d.greet();

    // Ambiguity2:
    d d1;
    d1.say();
    e e1;
    e1.say();


    return 0;
}