#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],p[maxn],book[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            book[i]=1;
        int mex=n;
        for(int i=n;i;i--){
            p[i]=mex-a[i];
            book[p[i]]=0;
            mex=min(mex,p[i]);
        }
        for(int i=1;i<=n;i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }
    return 0;
}