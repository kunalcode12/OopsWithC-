#include <iostream>
using namespace std;

class employee
{
    int id;
    static int count; // it is at default equal to 0 initially

public:
    void setvalue(void)
    {
        cout << "enter the employee id " << endl;
        cin >> id;
        count++;
    }

    void getvalue(void)
    {
        cout << "the id of this employee is " << id << " and employee number is " << count << endl;
    }

    static void getCount(void){
        cout<<"the count value is "<<count<<endl;  // after using static it could be called in int main() directly by class name 
    }
};

// NOTE = one static variable or fuction have access to only another static variable or function

// count is static data member of class employee
int employee::count = 1000; // default value is 0 and if i want to start any specific number then we add that value here not in class

int main()
{
    employee kunal, harry, cat; // all three of them is sharing one count variable
    // kunal.id=3;    // it is wrong as it is inside private class
    kunal.setvalue();
    kunal.getvalue();
    employee::getCount();

    harry.setvalue();
    harry.getvalue();
    employee::getCount();

    cat.setvalue();
    cat.getvalue();
    employee::getCount();

    return 0;
}