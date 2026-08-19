#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e8+10;
int T,n;
bool a[maxn];
int work(int x)
{
    if(x==1)return 1;
    for(int i=2;i<=x+10;i++)
        a[i]=0;
    a[1]=1;
    int ans=1,pos=2;
    while(pos<=x){
        for(int i=1;i*pos<=x;i++)
            a[i*pos]^=1;
        while(a[pos]==1)pos++;
        ans++;
    }
    return ans;
}
int main(){
    cin>>n;
    cout<<work(n);
    return 0;
}