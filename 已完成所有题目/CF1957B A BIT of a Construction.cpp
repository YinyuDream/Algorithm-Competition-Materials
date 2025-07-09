#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int count(int x){
    int num=0;
    while(x){
        num++;
        x&=(x-1);
    }
    return num;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int num=0;
        for(int i=1;i<=30;i++)
            if((1<<i)-1>k){
                num=i-1;
                break;
            }
        if(n==1){
            cout<<k<<endl;
        }else{
            if((1<<num)-1==k){
                cout<<k<<" ";
                for(int i=1;i<=n-1;i++)
                    cout<<0<<" ";
            }else{
                cout<<(1<<num)-1<<" "<<k-(1<<num)+1<<" ";
                for(int i=1;i<=n-2;i++)
                    cout<<0<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}