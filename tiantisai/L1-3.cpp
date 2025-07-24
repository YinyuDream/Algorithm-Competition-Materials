#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>35&&b==1&&c>=33){
        cout<<"Bu Tie"<<endl;
        cout<<a;
    }else{
        if(b==0&&a>35&&c>=33){
            cout<<"Shi Nei"<<endl;
            cout<<a;
        }else if(b==1&&(c<33||a<=35)){
            cout<<"Bu Re"<<endl;
            cout<<c;
        }else if(b==0&&(c<33||a<=35)){
            cout<<"Shu Shi"<<endl;
            cout<<c;
        }
    }
    return 0;
}