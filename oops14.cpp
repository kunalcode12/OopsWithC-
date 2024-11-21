#include<iostream>
#include<cmath>
using namespace std;

class point{
    int x,y,z;
    public:
        point(int a,int b){
            x=a;
            y=b;
        }
        friend int distance(point,point);
        /*point(point o1,point o2){    --> this can also be used for distance between two points
            int d;
            d=sqrt((o2.x-o1.x)*(o2.x-o1.x) + (o2.y-o1.y)*(o2.y-o1.y));
            cout<<d<<endl;
        }*/
        void displaynumber(){
            cout<<"the number is ("<<x<<","<<y<<")"<<endl;
        }
};

int distance(point o1,point o2){
    int d;
    d=sqrt((o2.x-o1.x)*(o2.x-o1.x) + (o2.y-o1.y)*(o2.y-o1.y));
    cout<<"distance "<<d<<endl;
    return d;

}



int main(){
    point u(1,1);//h(5,8);
    u.displaynumber();
    //h.displaynumber();
    point u1(1,1);
    u1.displaynumber();
    distance(u,u1);

    return 0;
}