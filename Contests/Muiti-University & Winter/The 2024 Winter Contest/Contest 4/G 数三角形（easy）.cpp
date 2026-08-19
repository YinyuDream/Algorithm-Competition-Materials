#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,ans,sum[maxn][maxn];
char s[maxn][maxn];
int count(int top,int mid)
{
    int cnt=0;
    for(int i=top+1;i<=n;i++){
        int x=i-top;
        if(mid-x<1||mid+x>m){
            break;
        }
        if(s[i-1][mid-(x-1)]!='*'||s[i-1][mid+(x-1)]!='*'){
            break;
        }
        if(sum[i][mid+x]-sum[i][mid-x-1]==2*x+1){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i]+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=sum[i][j-1];
            if(s[i][j]=='*'){
                sum[i][j]++;
            }
        }
    }
    for(int top=1;top<n;top++){
        for(int mid=2;mid<m;mid++){
            ans+=count(top,mid);
        }
    }
    cout<<ans<<endl;
}