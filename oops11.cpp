#include<iostream>
using namespace std;

class c2;
class c1{
    int val1;
    friend void exchanging(c1 &,c2 &);
    public:
        void setvalue(int a){
            val1=a;
        }
        void display(){
            cout<<val1<<endl;
        }

};

class c2{
    int val2;
    friend void exchanging(c1 &,c2 &);
    public:
        void setvalue(int a){
            val2=a;
        }
        void display(){
            cout<<val2<<endl;
        }

};

void exchanging(c1 &x , c2 &y){
    int tmp=x.val1;
    x.val1=y.val2;
    y.val2=tmp;
}

int main(){
    c1 a;
    a.setvalue(3);
    c2 b;
    b.setvalue(6);
    exchanging(a,b);

    cout<<"the value a after eschange  ";
    a.display();
    cout<<"the value b after eschange  ";
    b.display();
    return 0;
}