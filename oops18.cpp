#include <iostream>
using namespace std;

class bankdeposit
{
    int principle;
    int years;
    float interestrate;
    float returnvalue;

public:
    bankdeposit() {}     //--> we need this blank constructor so can compliler choose which constructor is need to be used
    bankdeposit(int p, int y, float r);
    bankdeposit(int p, int y, int r);
    void display();
};

bankdeposit::bankdeposit(int p, int y, float r)
{
    principle = p;
    years = y;
    interestrate = r;
    returnvalue = principle;
    for (int i = 0; i < y; i++)
    {
        returnvalue = returnvalue * (1 + interestrate);
    }
}

bankdeposit::bankdeposit(int p, int y, int r)
{
    principle = p;
    years = y;
    interestrate = float(r) / 100;
    returnvalue = principle;
    for (int i = 0; i < y; i++)
    {
        returnvalue = returnvalue * (1 + interestrate);
    }
}

void bankdeposit::display()
{
    cout << endl
         << "principal amount was " << principle << endl
         << "return value after years " << years << " is " << returnvalue << endl;
}

int main()
{
    bankdeposit bd1, bd2,bd3;    //-->to use this method we use blank constructor above otherwise in this method it will show error
    int p, y, R;
    float r;
    cout << "enter the value of p,y and r " << endl;
    cin >> p >> y >> r;
    bd1 = bankdeposit(p, y, r);
    //bankdeposit bd1(p,y,r);    --> this method is used if you dont make blank constructor
    bd1.display();

    cout << "enter the value of p,y and r " << endl;
    cin >> p >> y >> R;
    bd2 = bankdeposit(p, y, R);
    //bankdeposit bd2(p,y,R);   --> same like above
    bd2.display();
    return 0;
}