#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans,cnt;
int book[maxn],catlan[maxn];
bool check(int x)
{
    if(x==1)return 1;
    int lim=sqrt(x)+1;
    for(int i=2;i<=lim;i++)
        if(x%i==0)
            return false;
    return true;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        book[i]=1;
    for(int i=1;i<=n;i++)
        if(i%2==0)
            book[i]=0;
    for(int i=1;i<=n;i++)
        if(check(i))
            book[i]=0;
    for(int i=1;i*(i+1)/2<=n;i++)
        book[i*(i+1)/2]=0;
    catlan[0]=catlan[1]=1;
    cnt=2;
    while(true){
        catlan[cnt]=(4*cnt-2)*catlan[cnt-1]/(cnt+1);
        if(catlan[cnt]>n)
            break;
        cnt++;
    }
    for(int i=1;i<=cnt;i++)
            book[catlan[i]]=0;
    for(int i=1;i<=n;i++)
        ans+=book[i];
    cout<<ans;
    return 0;
}