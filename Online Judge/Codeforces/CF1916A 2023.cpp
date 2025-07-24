#include<bits/stdc++.h>
using namespace std;
int T,n,k,flag,pro,a[10];
int main(){
    cin>>T;
    while(T--){
        flag=true;
        pro=1;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            pro*=a[i];
            if(2023%a[i]!=0||2023%pro!=0){
                cout<<"NO"<<endl;
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl<<2023/pro<<" ";
            for(int i=1;i<k;i++)
                cout<<1<<" ";
            cout<<endl;
        }
    }
    return 0;
}