#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            b[i]=a[i]+i;
        for(int i=1;i<=n;i++){
            int p=upper_bound(b+1,b+n+1,i)-b;
            cout<<i-p+1<<' '; 
        }
        cout<<endl;
    }
    return 0;
}