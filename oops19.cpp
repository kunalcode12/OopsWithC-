#include<iostream>
using namespace std;

int count=0;   //-->this is global variable

class number{
    public:
        number(){
            count++;
            cout<<"this is the time when the constructor is called for object number "<<count<<endl;
        }
        ~number(){
            cout<<"this is the time when the destructor is called for object number"<<count<<endl;
            count--;
        }

};

int main(){
    cout<<"we are inside our main function "<<endl;
    cout<<"creating first object n1"<<endl;
    number n1;
    {
        cout<<"entering this block"<<endl;
        cout<<"creating two more objects"<<endl;
        number n2,n3;
        cout<<"exiting this block"<<endl;
    }
    cout<<"back to main"<<endl;
    return 0;
}