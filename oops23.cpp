#include<iostream>
using namespace std;

class base{
    protected:    // we made protected member as we dont want to share our private data
        int a;
    private:
        int b;
};
/*
for a protected member:    
                         public derivation       private derivation      protected derivation
1.private                 not inherited           not inherited            not inherited
2.protected               protected               private                   protected
3.public                  public                  private                   protected
*/
class derived: protected base{

};

int main(){
    base a;
    derived b;
    //cout<<a*b;    //here a will show error as a is protected member of base class as well as derived class
    return 0;
}