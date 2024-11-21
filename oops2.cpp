#include <iostream>
#include <string>
using namespace std;

// nesting of member function

class binary
{
    string s;    // by default private

public:
    void read(void);
    void chkBin(void);
    void onesCompliment(void);
    void display(void);
};

void binary::read(void)
{
    cout << "enter the binary number:" << endl;
    cin >> s;
}

void binary::chkBin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "invalid binary format " << endl;
            exit(0);
        }
        
    }
}

void binary:: onesCompliment(void) {
    chkBin();                        // with this we can hide this function from user and still use it also known as nesting of member function
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='0'){
            s.at(i)='1';
        }
        else{
            s.at(i)='0';
        }
    }

}

void binary::display(void){
    for(int i=0;i<s.length();i++){
        cout<<s.at(i);
    }

}

int main()
{
    binary h;
    h.read();
    //h.chkBin();
    h.onesCompliment();
    h.display();
    return 0;
}