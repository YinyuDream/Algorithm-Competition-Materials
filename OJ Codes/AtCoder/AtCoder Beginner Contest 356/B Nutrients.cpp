#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
int a[maxn],b[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            b[j]+=x;
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i]<a[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}