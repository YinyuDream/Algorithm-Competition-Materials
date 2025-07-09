#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n%2==0){
            for(int i=1;i<n;i++)
                cout<<1<<" "<<-2<<" ";
            cout<<1<<" "<<n-1<<endl;
        }else{
            if(n==3){
                cout<<"1 -1 2 1 -2 1"<<endl;
            }else{
                cout<<-1<<" "<<-2<<" ";
                for(int i=2;i<n;i++)
                    cout<<1<<" "<<-2<<" ";
                cout<<1<<" "<<n-3<<endl;
            }
        }
    }
    return 0;
}