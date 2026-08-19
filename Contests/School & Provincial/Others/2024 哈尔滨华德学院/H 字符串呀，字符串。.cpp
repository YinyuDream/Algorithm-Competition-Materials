#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,ans;
int f[maxn];
unsigned long long hsh[maxn][210];
string a[maxn];
bool cmp(string u,string v)
{
    return u.size()<v.size();
}
bool check(int u,int v)
{
    int len=a[u].size();
    return hsh[u][len-1]==hsh[v][len-1];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        int len=a[i].size();
        hsh[i][0]=a[i][0]-'a';
        for(int j=1;j<len;j++){
            hsh[i][j]=hsh[i][j-1]*131+a[i][j]-'a';
        }
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=i-1;j;j--){
            if(check(j,i)){
                f[i]=f[j]+1;
                break;
            }
        }
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}