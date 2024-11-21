#include<iostream>
using namespace std;

// base class
class employee{
    //int id;
    //float salary;
    public:
    int id;
    float salary;
       employee(int empid){
        id=empid;
        salary=89;
       }
       employee(){}
};

//derived class syntax
/*class{{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
   class members/methods/etc... 
}
note:
1.default visibility mode is private
2.private visibility mode : public memeber of the base class becomes the 
  private members of the derived class
3.public visibility mode : public memeber of the base class becomes the 
  public members of the derived class
4.private members are never inherited
*/

/*class programmer:public employee  ----> public member of base class will we public member of derived class */


class programmer:employee{      /*--> if there is no visibility mode than it is private memeber of derived class and even if in the base class 
                                     it was public it will still be a private memeber in derived class */
    public:
        programmer(int mpid){    //--> inherited item will be private which is id here
            id=mpid;
        }
        int languagecode=9;      //->whatever we create here can we private or public according to us
        void getdata(){
            cout<<id<<endl;      // with function inside we can access that private data
        }
};

int main(){
    //employee harry,mohan;    //-->this will not work as there is no default constructor
    employee harry(6),rohan(7);
    cout<<harry.salary<<endl;
    cout<<rohan.salary<<endl;

    programmer skillf(1);    //-->here 1 is the id =mpid
    cout<<skillf.languagecode<<endl;
    skillf.getdata();
    //skillf.id;  --> it will not work as the id is private member of derived class
    return 0;
}