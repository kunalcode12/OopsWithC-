#include<iostream>
using namespace std;

class shop{
    int itemid;
    float price;
    public:
        void setdata(int a,float b){
            itemid=a;
            price=b;
        }
        void getdata(){
            cout<<"code of this item is "<<itemid<<endl;
            cout<<"price of this item is "<<price<<endl;
        }
};
int main(){
    int size=3;
    //int*ptr=&size;     here we are using int data type
    //int*ptr=new int[34];   // here int[34] means to dinamically allocate the memory to store 34 integers
    // same above concept we will use in shop:
    shop*ptr=new shop[size];    // here i am making 3 objects of shop class  
                                // here we are using shop data type
    // here above ptr is pointing toward 1st object of shop and to make ptr pointer to point to other objects of shop class we use ptr++.
    shop*ptrtemp=ptr;   // here it is a new pointer which point at ptr 1st object
    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
       cout<<"enter id and price of item  "<<i+1<<endl;
       cin>>p>>q;
       //this can also be used
       //(*ptr).setdata(p,q);
       ptr->setdata(p,q);
       ptr++;
    }

    for(int i=0;i<size;i++){
        cout<<"item no = "<<i+1<<endl;
        ptrtemp->getdata();
        
        ptrtemp++;         // we are not using ptr++ here as after after initial for loop above the poninter will we pointing out of size length
                            // so to make the pointer inside the size we use ptrtemp which is initially pointing at at first object of ptr pointer
    }
    
    return 0;
}