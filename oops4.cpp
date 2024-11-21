#include<iostream>
using namespace std;

class shop{

    int itemId[100];
    int itemPrice[100];
    int counter;

    public:
    void initcounter(){
        counter=0;
    }
    void getdetails(void);
    void display(void);


};

void shop::getdetails(void){
    cout<<"enter the id of item "<<counter +1 <<endl;
    cin>>itemId[counter];
    cout<<"enter price of item "<<endl;
    cin>>itemPrice[counter];
    counter++;
}

void shop::display(void){
    for(int i=0;i<counter;i++){
        cout<<"the price of item with id "<<itemId[i]<< " is " <<itemPrice[i]<<endl;
    }
}

int main(){
    int n;
    shop amazon;
    amazon.initcounter();
    cout<<"enter the no of inputs :"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        amazon.getdetails();
    }

    //amazon.getdetails();
    //amazon.getdetails();
    //amazon.getdetails();
    amazon.display();
    
    return 0;
}