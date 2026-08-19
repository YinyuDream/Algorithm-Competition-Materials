#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k;
int a[maxn],cnt;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        if(n%i==0)
            a[++cnt]=i;
    if(cnt<k)printf("-1");
    else printf("%d",a[k]);
    return 0;
}