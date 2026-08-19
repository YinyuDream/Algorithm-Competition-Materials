#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int T;
int a[maxn],b[maxn],pos[maxn];
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=n;i>1;i--){
        int old=pos[b[i]];
        if(old==i) continue;
        for(int j=1;j<old;j++)
            cout<<1;
        for(int j=old+1;j<=i;j++)
            cout<<2;
        for(int j=i;j<=n;j++)
            cout<<1;
        for(int j=old;j<i;j++)
            a[j]=a[j+1];
        a[i]=b[i];
        for(int j=1;j<=n;j++)
            pos[a[j]]=j;
    }
    cout<<endl;
}
int main(){
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}