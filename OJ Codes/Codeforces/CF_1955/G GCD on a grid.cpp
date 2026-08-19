#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
typedef long long ll;
int T,n,m;
int a[maxn][maxn];
int st[maxn][maxn][501]; // 使用三维数组模拟 vector
int sz[maxn][maxn]; // 记录每个位置的 vector 的大小
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        st[1][1][0] = a[1][1];
        sz[1][1] = 1;
        
        for(int i=2;i<=m;i++){
            for(int k=0;k<sz[1][i-1];k++){ // 遍历之前的数组元素
                int j = st[1][i-1][k];
                st[1][i][sz[1][i]] = __gcd(j, a[1][i]);
                sz[1][i]++;
            }
            sort(st[1][i], st[1][i] + sz[1][i]);
            sz[1][i] = unique(st[1][i], st[1][i] + sz[1][i]) - st[1][i];
        }
        
        for(int i=2;i<=n;i++){
            for(int k=0;k<sz[i-1][1];k++){ // 遍历之前的数组元素
                int j = st[i-1][1][k];
                st[i][1][sz[i][1]] = __gcd(j, a[i][1]);
                sz[i][1]++;
            }
            sort(st[i][1], st[i][1] + sz[i][1]);
            sz[i][1] = unique(st[i][1], st[i][1] + sz[i][1]) - st[i][1];
        }
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                for(int k=0;k<sz[i-1][j];k++){ // 遍历之前的数组元素
                    int l = st[i-1][j][k];
                    st[i][j][sz[i][j]] = __gcd(l, a[i][j]);
                    sz[i][j]++;
                }
                for(int k=0;k<sz[i][j-1];k++){ // 遍历之前的数组元素
                    int l = st[i][j-1][k];
                    st[i][j][sz[i][j]] = __gcd(l, a[i][j]);
                    sz[i][j]++;
                }
                sort(st[i][j], st[i][j] + sz[i][j]);
                sz[i][j] = unique(st[i][j], st[i][j] + sz[i][j]) - st[i][j];
            }
        }
        
        int ans=0;
        for(int k=0;k<sz[n][m];k++){ // 遍历最后一个位置的数组元素
            ans=max(ans,st[n][m][k]);
        }
        cout<<ans<<endl;
        
        // 清空数组
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                sz[i][j] = 0;
                memset(st[i][j], 0, sizeof(st[i][j]));
            }
    }
    return 0;
}
