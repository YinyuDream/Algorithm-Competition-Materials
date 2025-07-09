#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,ans,cnt;
long long m,sum;
struct node{
    int id,p,type;
}a[maxn];
bool book[maxn];
bool cmp(node a,node b)
{
    return a.p<b.p;
}
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i*2-1].p>>a[i*2].p;
        a[i*2-1].id=a[i*2].id=i;
        a[i*2-1].type=1;
        a[i*2].type=2;
    }
    sort(a+1,a+n*2+1,cmp);
    for(int i=1;i<=n*2;i++){
        if(book[a[i].id]==false&&cnt<k){
            book[a[i].id]=true;
            sum+=a[i].p;
            ans++;
            if(sum>m){
                break;
            }
        }
    }
    if(sum>m)cout<<ans-1;
    else cout<<ans;
    return 0;
}