#include<bits/stdc++.h>
using namespace std;
int T,n;

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<=(n-3)/2;i++){
            cout<<1;
            for(int j=1;j<=i;j++)
                cout<<0;
            cout<<6;
            for(int j=1;j<=i;j++)
                cout<<0;
            cout<<9;
            for(int j=1;j<=n-2*i-3;j++)
                cout<<0;
            cout<<endl;
        }
        for(int i=0;i<=(n-3)/2;i++){
            cout<<9;
            for(int j=1;j<=i;j++)
                cout<<0;
            cout<<6;
            for(int j=1;j<=i;j++)
                cout<<0;
            cout<<1;
            for(int j=1;j<=n-2*i-3;j++)
                cout<<0;
            cout<<endl;
        }
        if(n>=3){
            cout<<196;
        }else{
            cout<<1;
        }
        for(int i=1;i<=n-3;i++)
            cout<<0;
        cout<<endl;
    }
    return 0;
}