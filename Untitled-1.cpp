#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int arr1[3];
        for(int i=0;i<3;i++){
            cin>>arr1[i];
        }
        int arr2[3];
        for(int i=0;i<3;i++){
            cin>>arr2[i];
        }
        int sum1=0;
        int sum2=0;
        for(int i=0;i<3;i++){
            sum1+=arr1[i];
            sum2+=arr2[i];
        }
        //bool dragonPrinted = false;
        for(int i=0;i<3;i++){
            if(sum1>sum2){
                cout<<"DRAGON"<<endl;
                //dragonPrinted = true;
                break;
            }
            else if(sum2>sum1){
                cout<<"SLOTH"<<endl;
                break;
            }
            else {
                int winner=0;
                for(int i=0;i<3;i++){
                    if(arr1[i]>arr2[i]){
                        winner=1;
                        break;
                    }
                    else if(arr1[i]<arr2[i]){
                        winner =-1;
                        break;
                    }
                }
                if(winner==1){
                    cout<<"DRAGON"<<endl;
                    //dragonPrinted = true;
                    break;
                    
                }
                else if(winner==-1){
                    cout<<"SLOTH"<<endl;
                    break;
                }
                else{
                    cout<<"TIE"<<endl;
                    break;
                }
                
            }
        }
        
    }    
    return 0;
}
