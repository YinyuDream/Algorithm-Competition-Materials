#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int T,n,sum;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]%=2;
        }
        a[n+1]=a[1];
        for(int i=1;i<=n;i++)
            if(a[i]!=a[i+1])
                sum++;
        sum=n-sum;
        if(sum%2==1)cout<<"qcjj"<<endl;
        else cout<<"zn"<<endl;
    }
    return 0;
}