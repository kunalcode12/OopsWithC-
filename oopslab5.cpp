#include<iostream>
using namespace std;

class student{
    protected:
        int id;
    public:
        void setrollno(int);
        void getrollno();
};

void student::setrollno(int r){
    id=r;
}
void student::getrollno(){
    cout<<"the roll no id "<<id<<endl;
}

class exam:public student{
    protected:
        float maths;
        float physics;
    public:
        void setmarks(float ,float);
        void getmarks();
};

void exam::setmarks(float m1,float m2){
    maths=m1;
    physics=m2;
}

void exam::getmarks(){
    cout<<"the marks in maths is "<<maths<<endl;
    cout<<"the marks in maths is "<<physics<<endl;
}

class result: public exam{
    float percentage;
    public:
        void display();
};

void result::display(){
    getrollno();    
    getmarks();
    cout<<"percentage of student is "<<maths+physics/2<<endl;
}

int main(){

    /*
    Notes:
         if you are inheriting B from A and C from B:[A-->B-->C]
         1.A is the base class of B and B is the base class of C
         2.A-->B-->C is called inheritance class
    */
    result kunal;
    kunal.setrollno(6);
    kunal.setmarks(99.9,95.7);
    //kunal.getrollno();   // we can also access this function from here
    kunal.display();

    return 0;
}