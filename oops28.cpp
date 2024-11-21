#include<iostream>
using namespace std;
/*
student class --> test class    //--> here student is virtual base class same for sports class below
student class --> sports class
test class --> result class
sports class --> result class
*/
 class student{
    protected:
        int id;
    public:
        void setid(int a){
            id=a;
        }
        void printid(){
            cout<<"your id is "<<id<<endl;
        }
 };

class test:virtual public student{
    protected:
        float maths;
        float physics;
    public:
        void setmarks(float m1,float p1){
            maths=m1;
            physics=p1;
        }
        void printmarks(){
            cout<<"marks of maths "<<maths<<endl<<"marks of physics "<<physics<<endl;
        }
};
class sports:virtual public student{
    protected:
        float score;
    public:
        void setscore(float s){
            score=s;
        }
        void printscore(){
            cout<<"your sports marks is "<<score<<endl;
        }
};

class result : public test, public sports{
    private:
        float total;
    public:
        void display(){
            total=maths+physics+score;
            printid();
            printmarks();
            printscore();
            cout<<"your total score is "<<total<<endl;
        }
};
int main(){
    result harry;
    harry.setid(6);     // here id was coming from class test and class sports so to resolve ambiguity we take virtual class student in both test and sports class
    harry.setmarks(7,9);
    harry.setscore(4);
    harry.display();
    return 0;
}