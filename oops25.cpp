// multiple inheritance

#include<iostream>
using namespace std;

/*
SYNTAX WHEN INHERITING FROM MORE THAN ONE BASE CLASS:

class derivedC: {visibility-mode base1},{visibility-mode base2}
{
    class body of class "derivedC"
}
*/

class base1{
    protected:
        int base1int;
    public:
        void setbase1int(int a){
            base1int=a;
        }

};

class base2{
    protected:
        int base2int;
    public:
        void setbase2int(int a){
            base2int=a;
        }
};

class base3{
    protected:
        int base3int;
    public:
        void setbase3int(int a){
            base3int=a;
        }
};

class derived:public base1,public base2,public base3{
    public:
        void show(){
            cout<<"the value of base1 is "<<base1int<<endl;
            cout<<"the value of base2 is "<<base2int<<endl;
            cout<<"the value of base3 is "<<base3int<<endl;
            cout<<"the sum of base1 and base2 is "<<base1int+base2int+base3int<<endl;
        }
};
/*
The inherited derived class will look something like this:
Data Members:
     base1int -->protected
     base2int -->protected
Members Function:
     setbase1int() --> public
     setbase2int() --> public
     void show()  --> public
*/
int main(){
    derived kunal;
    kunal.setbase1int(7);
    kunal.setbase2int(5);
    kunal.setbase3int(6);
    kunal.show();
    return 0;
}