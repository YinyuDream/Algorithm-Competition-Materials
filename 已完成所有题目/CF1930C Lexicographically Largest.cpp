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
            cin>>a[i],a[i]+=i;
        sort(a+1,a+n+1);
        for(int i=n-1;i;i--)
            if(a[i]>=a[i+1])
                a[i]=a[i+1]-1;
        for(int i=n;i;i--)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}