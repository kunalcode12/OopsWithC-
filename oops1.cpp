#include<iostream>
using namespace std;

class animal{
    private:
        int age,Snumber;
        string name;


    public:
        char type;
        int children;
        void getvalue(int a,int b,string c);
        void outvalue(){
            cout<<"animal name is "<<name<<endl;
            cout<<"animal Snumber"<<Snumber<<endl;
            cout<<"animal age "<<age<<endl;
            cout<<"animal type "<<type<<endl;
            cout<<"animal children "<<children<<endl;
        }

};

void animal::getvalue(int a,int b,string c){
    age=a;
    Snumber=b;
    name=c;
}

int main(){
    animal tiger;
    tiger.getvalue(10,1,"shimba");
    tiger.type='s';
    tiger.children=2;
    tiger.outvalue();
    return 0;
}