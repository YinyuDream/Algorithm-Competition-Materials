#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
int T,n,m;
int a[maxn][maxn],f[maxn][maxn],g[maxn][maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j],f[i][j]=0,g[i][j]=1e9;
        f[0][0]=1,g[0][0]=0;
        for(int i=1;i<n;i++){
            f[i][0]|=f[i-1][0]&&(!a[(2*i)%n][0]&&!a[(2*i-1)%n][0]);
            if(f[i][0]==1)g[i][0]=g[i-1][0]+1;
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                f[i][j]|=f[i][j-1]&&(!a[(2*i+j)%n][j]);
                if(f[i][j]==1)g[i][j]=g[i][j-1]+1;
            }
            for(int i=0;i<n;i++){
                if(f[i-1][j]&&(!a[(2*i+j)%n][j]&&!a[(2*i+j-1)%n][j])){
                    f[i][j]=1;
                    g[i][j]=min(g[i][j],g[i-1][j]+1);
                }
            }
            if(f[n-1][j]&&(!a[(0+j)%n][j]&&!a[(0+j-1)%n][j])){
                f[0][j]=1;
                g[0][j]=min(g[0][j],g[n-1][j]+1);
            }
            for(int i=0;i<n;i++){
                if(f[i-1][j]&&(!a[(2*i+j)%n][j]&&!a[(2*i+j-1)%n][j])){
                    f[i][j]=1;
                    g[i][j]=min(g[i][j],g[i-1][j]+1);
                }
            }
        }
        int minx=1e9;
        for(int i=0;i<n-1;i++)
            minx=min(minx,g[i][m-1]+i+1);
        int ans=min(minx,g[n-1][m-1]);
        if(ans==1e9)cout<<-1;
        else cout<<ans;
        cout<<endl;
	}
	return 0;
}