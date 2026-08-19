#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=6){
            if(n==1)cout<<"1";
            if(n==2)cout<<"1 2";
            if(n==3)cout<<"1 2 3";
            if(n==4)cout<<"3 2 1 4";
            if(n==5)cout<<"5 2 1 4 3";
            if(n==6)cout<<"6 5 2 1 4 3";
        }else if(n%3==1){
            int lmx=(n-2)/3*3+2,rmx=lmx+1;
            for(int i=1;i<=lmx-7;i+=3)
                cout<<i<<" ";
            for(int i=lmx;i>=2;i-=3)
                cout<<i<<" ";
            for(int i=3;i<=rmx;i+=3)
                cout<<i<<" ";
            for(int i=rmx-5;i<=n;i+=3)
                cout<<i<<" ";
        }else{
            int lmx=(n-2)/3*3+2,rmx=lmx-1;
            for(int i=n/3*3;i>=lmx-5;i-=3)
                cout<<i<<" ";
            for(int i=lmx;i>=2;i-=3)
                cout<<i<<" ";
            for(int i=1;i<=rmx;i+=3)
                cout<<i<<" ";
            for(int i=rmx-7;i>=3;i-=3)
                cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}