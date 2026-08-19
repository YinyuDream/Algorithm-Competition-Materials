#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,ans;
int a[maxn][maxn],up[maxn][maxn],s[maxn][maxn];
stack<int>st;
int main(){
	//freopen("matrix.in","r",stdin);
	//freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++)
		up[1][i]=(a[1][i]==0?1:0);
	for(int j=1;j<=m;j++)
		for(int i=2;i<=n;i++)
		{
			if(a[i][j]==0&&a[i-1][j]==0)
			up[i][j]=up[i-1][j]+1;
			else if(a[i][j]==0&&a[i-1][j]!=0)
			up[i][j]=1;
			else up[i][j]=0;
		}
	for(int i=1;i<=n;i++)
	{
		while(st.size())st.pop();
		for(int j=1;j<=m+1;j++)
		{
			while(st.size()&&up[i][st.top()]>up[i][j])
			s[i][st.top()]=(j-st.top())*up[i][st.top()],st.pop();
			if(st.empty()||up[i][st.top()]<=up[i][j])st.push(j);
		}
		while(st.size())st.pop();
		for(int j=m;j>=0;j--)
		{
			while(st.size()&&up[i][st.top()]>up[i][j])
			s[i][st.top()]+=(st.top()-j-1)*up[i][st.top()],st.pop();
			if(st.empty()||up[i][st.top()]<=up[i][j])st.push(j);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,s[i][j]);
	printf("%d",ans);
	return 0;
}