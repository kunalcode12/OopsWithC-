#include<iostream>
#include<string>
using namespace std;

class binary{
    string s;

    public:
    void read(void);
    void chkBin(void);
    void onesCompliment(void);
    void displayBin(void);

    /*void read(void){                                     <----this can also be used here we can use (void) or () both is valid
        cout<<"enter the binary binary number "<<endl;
        cin>>s;
    }
    void chkBin(void){
        for(int i=0;i<s.length();i++){
        if(s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"invalid number "<<endl;
            exit(0);

        }
        }
    }
    void onesCompliment(void){
        for(int i=0;i<s.length();i++){
        if(s.at(i)='0'){
            s.at(i)='1';
        }
        else{
            s.at(i)='0';
        }
        } 
    }
    void displayBin(void){
        for(int i=0;i<s.length();i++){
        cout<<s.at(i);
        }
    }*/

};

void binary::read(void){               
    cout<<"enter the binary binary number "<<endl;
    cin>>s;
}

void binary::chkBin(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"invalid number "<<endl;
            exit(0);

        }
    }
}

void binary::onesCompliment(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i)='0'){
            s.at(i)='1';
        }
        else{
            s.at(i)='0';
        }
    }
}

void binary::displayBin(void){
    for(int i=0;i<s.length();i++){
        cout<<s.at(i);
    }

}

int main(){
    binary g;
    g.read();
    g.chkBin();
    g.onesCompliment();
    g.displayBin();
    
    return 0;
}