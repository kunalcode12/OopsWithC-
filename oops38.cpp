#include<iostream>
using namespace std;

class cwh{   // this is abstract base class which means we cannot use this class to create objects
            // this is designed only for the purpose to get inherited by other classes
            // it also must have atleast one pure virtual function
    protected:
        string title;
        float rating;
    public:
        cwh(string s,float r):title(s),rating(r){}
        virtual void display()=0;  // it is a do nothing function->pure virtual function 
                                   // this also means it is must for every derived class to have a function display otherwise compiler will show error
                                   // as it is must to override pure virtual function 
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

    cwhvideo rjvideo(title,rating,video);  
    //rjvidep.display();  

    title="something more ";
    rating=4.7;
    text=7;
    cwhtext rjtext(title,rating,text);
    //rjtext.display();
    
    cwh* tuts[2];  
    tuts[0]=&rjvideo;   
    tuts[1]=&rjtext;

    tuts[0]->display(); // both of them are working as there is virtual function above 
    tuts[1]->display();



    return 0;
}