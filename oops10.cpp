#include<iostream>
using namespace std;

class y;

class x{
    int data;
    public:
        void setvalue(int value){
            data =value;
        }
        friend void add(x,y);

};

class y{
    int num;
    public:
        void setvalue(int value){
            num=value;
        }
        friend void add(x,y);

};

void add(x o1, y o2){
    cout<<"summing data of x and y give me "<<o1.data + o2.num;
}

int main(){
    x c1;
    y c2;
    c1.setvalue(4);
    c2.setvalue(7);
    add(c1,c2);
    
    return 0;
}