#include<iostream>
using namespace std;

// rules for virtual function
//1.they cannot be static
//2.they are assesed by object pointer
//3.virtual functions can be a friend of another class
//4.a virtual function in base class might not we used
//5.if a virtual function is defined in a base class there is no neccesity of redefyning it in the derived class

class cwh{
    protected:
        string title;
        float rating;
    public:
        cwh(string s,float r):title(s),rating(r){}
        virtual void display(){}  // if i remove the virtual here then the inherited classes display() will not work the output will only show 
                                   // this display
};

class cwhvideo:public cwh{
    float videolength;
    public:
        cwhvideo(string s,float r,float vl):cwh(s,r),videolength(vl){}
        void display(){
            cout<<"this is an amazing video with title "<<title<<endl;
            cout<<"rating of video is "<<rating<<endl;
            cout<<"length of videos is "<<videolength<<endl;
        }
};

class cwhtext:public cwh{
    int text;
    public:
        cwhtext(string s,float r,int wc):cwh(s,r),text(wc){}
        void display(){
            cout<<"this is an amazing text tutorial with title "<<title<<endl;
            cout<<"rating of text tutoria  is "<<rating<<" out of 5 stars"<<endl;
            cout<<"length of words is "<<text<<endl;
        }
};
int main(){
    string title;
    float rating,video;
    int text;
    title="something ";
    rating=4.7;
    video=7.89;
    //text=7;

    cwhvideo rjvideo(title,rating,video);  // compiler will choose automatically which display() to run
    //rjvideo.display();  // method to run the function

    //now using the pointer to run the avove method which is rj.display()
    title="something more ";
    rating=4.7;
    text=7;
    cwhtext rjtext(title,rating,text);
    //rjtext.display();
    // using pointer to display both at same time
    cwh* tuts[2];  // here we made two pointers
    tuts[0]=&rjvideo;  // nnever forget to use & to the function you are pointing 
    tuts[1]=&rjtext;

    tuts[0]->display(); // both of them are working as there is virtual function above 
    tuts[1]->display();



    return 0;
}