#include<iostream>
using namespace std;

class planet{
    protected:
        int a=4;
    public:
        void setData(int x){
            a=x;
        }
        void display();

};

void planet::display(){
    cout<<"the value of a is "<<a<<endl;
}

class earth:public planet{
    public:
    int c=10;
    void display(){
        cout<<"the value of a is "<<c<<endl;
    }
};

class mars:public planet{
    public:
        int d=2;
        void display(){
            cout<<"the value of a is "<<d<<endl;
        }
};

int main(){
    planet h1;
    h1.display();
    earth h2;
    h2.display();
    mars h3;
    h3.display();
    return 0;
}