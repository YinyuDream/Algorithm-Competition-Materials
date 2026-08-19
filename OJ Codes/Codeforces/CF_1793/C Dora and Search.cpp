#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int l=1,r=n,mx=n,mn=1;
        while(l<=r){
            bool flag=0;
            while(a[l]==mn)
                l++,mn++,flag=1;
            while(a[r]==mx)
                r--,mx--,flag=1;
            while(a[l]==mx)
                l++,mx--,flag=1;
            while(a[r]==mn)
                r--,mn++,flag=1;
            if(!flag)
                break;
        }
        if(r-l<3)
            cout<<-1<<endl;
        else
            cout<<l<<" "<<r<<endl;
    }
    return 0;
}