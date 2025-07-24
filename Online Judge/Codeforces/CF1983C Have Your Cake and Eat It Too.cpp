#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int work(vector<vector<int>> &a,int order[],int l[],int r[],ll lim,int n){
    for(int i=1;i<=3;i++)
        l[i]=r[i]=0;
    l[order[0]]=1;
    ll sum=0;
    for(int i=l[order[0]];i<=n;i++){
        sum+=a[order[0]][i];
        if(sum>=lim){
            r[order[0]]=i;
            break;
        }
    }
    if(!r[order[0]])return 0;
    l[order[1]]=r[order[0]]+1;
    sum=0;
    for(int i=l[order[1]];i<=n;i++){
        sum+=a[order[1]][i];
        if(sum>=lim){
            r[order[1]]=i;
            break;
        }
    }
    if(!r[order[1]])return 0;
    l[order[2]]=r[order[1]]+1;
    sum=0;
    for(int i=l[order[2]];i<=n;i++){
        sum+=a[order[2]][i];
        if(sum>=lim){
            r[order[2]]=i;
            break;
        }
    }
    if(!r[order[2]])return 0;
    r[order[2]]=n;
    return 1;
}
void solve(){
    int n;
    ll tot=0;
    cin>>n;
    vector<vector<int>> a(4,vector<int>(n+1));
    for(int i=1;i<=n;i++)
        cin>>a[1][i],tot+=a[1][i];
    for(int i=1;i<=n;i++)
        cin>>a[2][i];
    for(int i=1;i<=n;i++)    
        cin>>a[3][i];
    ll lim=tot/3+(tot%3!=0);
    int order[]={1,2,3};
    int l[]={0,0,0,0},r[]={0,0,0,0};
    int can=0;
    do{
        can|=work(a,order,l,r,lim,n);
        if(can)
            break;
    }while(next_permutation(order,order+3));
    if(can){
        for(int i=1;i<=3;i++)
            cout<<l[i]<<" "<<r[i]<<" ";
        cout<<endl;
    }
    else
        cout<<-1<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}