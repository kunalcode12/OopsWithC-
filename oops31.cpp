#include<iostream>
using namespace std;

// pointers basic examples
int main(){
    int a=4;
    int*ptr=&a;
    cout<<"value of a is "<<*ptr<<endl;

    // new operator for pointers
    //int*p=new int(40);     --> this kewords can we used for differnt data types like int, float, char etc.
    float*p=new float(40.78);
    cout<<"the value at address p is "<<*p<<endl;

    // dynimacly making array using pointer
    int*arr=new int[3];
    arr[0]=10;
    *(arr +1)=20;    // this can also we used to allocate the memmory
    //arr[1]=20;
    arr[2]=30;
    delete[] arr;   // it will free the dynamically allocated array 
    cout<<" the value at arr[0]"<<arr[0]<<endl;
    cout<<" the value at arr[1]"<<arr[1]<<endl;
    cout<<" the value at arr[2]"<<arr[2]<<endl;

    // delete operator
         // delete[]   --> this can also we used in freeing the data af dynamically allocated int , float or any block of memory like arr
    return 0;
}