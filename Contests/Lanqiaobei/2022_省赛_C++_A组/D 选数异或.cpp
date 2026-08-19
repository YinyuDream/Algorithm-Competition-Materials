#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,m,k;
int a[maxn],b[maxn],r[maxn],minx[maxn][20];
vector<int>pos[maxn];

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]^k;
        pos[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(pos[b[i]].empty()){
            r[i]=n+1;
        }else{
            auto num=lower_bound(pos[b[i]].begin(),pos[b[i]].end(),i);
            if(num==pos[b[i]].end())
                r[i]=n+1;
            else
                r[i]=*num;
        }
        minx[i][0]=r[i];
    }
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            minx[j][i]=min(minx[j][i-1],minx[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1,l,r;i<=m;i++){
        cin>>l>>r;
        int k=log2(r-l+1),mn=min(minx[l][k],minx[r-(1<<k)+1][k]);
        if(mn<=r){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}