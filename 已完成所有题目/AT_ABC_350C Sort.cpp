#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,tot;
int a[maxn],pos[maxn],l[maxn],r[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int p=pos[i];
        if(i==p)continue;
        swap(a[p],a[i]);
        pos[a[p]]=p;
        pos[a[i]]=i;
        l[++tot]=i;
        r[tot]=p;
    }
    cout<<tot<<endl;
    for(int i=1;i<=tot;i++){
        cout<<l[i]<<" "<<r[i]<<endl;
    }
    return 0;
}