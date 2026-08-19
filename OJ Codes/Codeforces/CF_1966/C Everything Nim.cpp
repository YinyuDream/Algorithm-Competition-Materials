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
        sort(a+1,a+n+1);
        int cnt=unique(a+1,a+n+1)-a-1;
        int flag=1;
        for(int i=cnt-1;i>=1;i--){
            if(a[i]-a[i-1]==1)flag^=1;
            if(a[i]-a[i-1]>1&&flag==0)flag=1;
        }
        if(flag)cout<<"Alice";
        else cout<<"Bob";
        cout<<endl;
    }
    return 0;
}