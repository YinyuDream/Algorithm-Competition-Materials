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
        int cnt=0,pos=n/2+(n%2!=0);
        for(int i=pos;i<=n;i++)
            if(a[i]==a[pos])
                cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}