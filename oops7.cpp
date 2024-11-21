#include<iostream>
using namespace std;

class employee{
    int empId;
    int salary;

    public:
        void setid(void){
            salary=676;
            cout<<"enter the id of the employee"<<endl;
            cin>>empId;
        }

        void getid(void){
            cout<<"the id of the employee is "<<empId<<endl;
        }

};

int main(){
    employee insta[4];
    for(int i=0;i<4;i++){
        insta[i].setid();
        insta[i].getid();
    }
    
    
    return 0;
}