#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m,x;
int a[maxn][maxn];
long long sum;
int main(){
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j],sum+=a[i][j];
    if(sum!=x){
        cout<<"wrong answer";
        return 0;
    }
    int num=0;
    for(int i=1;i<=n;i++){
        num^=a[i][1];
    }
    for(int i=2;i<=m;i++){
        int t=0;
        for(int j=1;j<=n;j++){
            t^=a[j][i];
        }
        if(t!=num){
            cout<<"wrong answer";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=m;j++){
            t^=a[i][j];
        }
        if(t!=num){
            cout<<"wrong answer";
            return 0;
        }
    }
    cout<<"accepted";
    return 0;
}