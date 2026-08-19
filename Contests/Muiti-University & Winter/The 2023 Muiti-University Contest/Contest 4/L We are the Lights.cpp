#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,q;
int row[maxn],col[maxn];
long long ans;
struct node{
    int dir,pos,wk;
}a[maxn];
int main(){
    cin>>n>>m>>q;
    for(int i=1,num;i<=q;i++){
        string s;
        cin>>s;
        if(s=="row"){
            cin>>num>>s;
            a[i]={1,num,s=="on"?1:0};
        }else{
            cin>>num>>s;
            a[i]={2,num,s=="on"?1:0};
        }
    }
    for(int i=q;i;i--){
        if(a[i].dir==1){
            if(row[a[i].pos]==1)
                continue;
            row[a[i].pos]=1;
            row[0]++;
            if(a[i].wk==1)
                ans=ans+m-col[0];
        }else{
            if(col[a[i].pos]==1)
                continue;
            col[a[i].pos]=1;
            col[0]++;
            if(a[i].wk==1)
                ans=ans+n-row[0];
        }
    }
    cout<<ans<<endl;
    return 0;
}