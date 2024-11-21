#include<iostream>
using namespace std;

class simplecalculator{
    protected:
        int num1;
        int num2;
    public:
        void inputsimple(int a,int b){
            num1=a;
            num2=b;
        }
        void performtasks();
};
void simplecalculator::performtasks(){
    cout<<"addition = "<<num1+num2<<endl;
    cout<<"subtraction = "<<num1-num2<<endl;
    cout<<"multiplication = "<<num1*num2<<endl;
    cout<<"division = "<<num1/num2<<endl;

}

class scientificcalc{
    protected:
        int n1;
        int n2;
    public:
        void inputscientific(int c,int d){
            n1=c;
            n2=d;
        }
        void performscientific(){
            cout<<"percentage = "<<n1+n2/100<<endl;
            cout<<"average = "<<n1+n2/2<<endl;
            cout<<"maximum = "<<max(n1,n2)<<endl;
            cout<<"minimum = "<<min(n1,n2)<<endl;
        }

};

class hybridcalc:public simplecalculator,public scientificcalc{
    public:
        void showevery(){
            performtasks();
            performscientific();
            cout<<"end of code"<<endl;
        }
};
    
int main(){
    hybridcalc c;
    c.inputsimple(6,9);
    c.inputscientific(7,3);
    c.showevery();
    return 0;
}