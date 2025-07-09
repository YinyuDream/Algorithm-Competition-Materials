#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn],b[maxn];
long long f[maxn][8],ans;
template<typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T, typename... Args>
T findMax(T a, Args... args) {
    return findMax(a, findMax(args...));
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    if(b[1]==0&&b[2]==1)
        f[1][1]=a[1];
    if(b[1]==1)
        f[1][3]=a[1];
    for(int i=2;i<=n;i++){
        if(b[i]==0){
            f[i][0]=findMax(f[i-1][0],f[i-1][2],f[i-1][3],f[i-1][4]);
            if(b[i+1]==1)f[i][1]=findMax(f[i-1][0],f[i-1][2],f[i-1][3],f[i-1][4])+a[i];
            if(b[i-1]==1)f[i][2]=findMax(f[i-1][5],f[i-1][6])+a[i];
        }else{
            f[i][3]=findMax(f[i-1][0],f[i-1][2],f[i-1][3],f[i-1][4])+a[i];
            f[i][4]=findMax(f[i-1][1],f[i-1][7]);
            f[i][5]=findMax(f[i-1][0],f[i-1][2],f[i-1][3],f[i-1][4]);
            if(b[i-1]==1)f[i][6]=findMax(f[i-1][5],f[i-1][6])+a[i];
            if(b[i+1]==1)f[i][7]=findMax(f[i-1][1],f[i-1][7])+a[i];
        }
    }
    for(int i=0;i<=7;i++)
        ans=max(ans,f[n][i]);
    cout<<ans<<endl;
    return 0;
}