#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,k;
vector<int>a[maxn],b[maxn];
double ans1,ans2;
int main(){
    cin>>n>>m>>k;
    for(int i=1,u,v;i<=k;i++){
        cin>>u>>v;
        a[u].push_back(v);
        b[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        double sum=1.0;
        for(int j=0;j<a[i].size();j++){
            sum*=(1.0*b[a[i][j]].size()-1)/b[a[i][j]].size();
        }
        ans1+=1-sum;
    }
    for(int i=1;i<=m;i++){
        double sum=1.0;
        for(int j=0;j<b[i].size();j++){
            sum*=(1.0*a[b[i][j]].size()-1)/a[b[i][j]].size();
        }
        ans2+=1-sum;
    }
    cout<<"float"<<endl;
    printf("%.8f %.8f",ans1,ans2);
    return 0;
}