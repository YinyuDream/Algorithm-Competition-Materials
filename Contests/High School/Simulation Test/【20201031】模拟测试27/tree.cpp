#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=510;
int T,n;
int a[maxn];
bool flag,f[maxn][maxn][maxn],book[maxn][maxn][maxn];
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
bool dfs(int l,int r,int root)
{
	if(book[l][r][root])return f[l][r][root];
	book[l][r][root]=true;
	if(l>=r)return f[l][r][root]=true;
	if(root==l)
		for(int i=l+1;i<=r;i++)
			if(gcd(a[l],a[i])>1&&dfs(l+1,r,i))
				return f[l][r][root]=true;
	else if(root=r)
		for(int i=l;i<r;i++)
			if(gcd(a[r],a[i])>1&&dfs(l,r-1,i))
				return f[l][r][root]=true;
	else
		for(int i=l;i<root;i++)
			for(int j=root+1;j<=r;j++)
				if(gcd(a[i],a[root])>1&&gcd(a[root],a[j])>1)
					if(dfs(l,root-1,i)&&dfs(root+1,r,j))
						return f[l][r][root]=true;
	return f[l][r][root]=false;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=0;
		memset(f,0,sizeof f);
		memset(book,0,sizeof book);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(dfs(1,n,i)){
				puts("YES");
				flag=true;
				break;
			}
		}
		if(!flag)
			puts("NO");
	}
	return 0;
}
