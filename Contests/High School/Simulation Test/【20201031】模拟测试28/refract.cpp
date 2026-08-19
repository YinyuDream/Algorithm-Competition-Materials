#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=6e3+10,p=1e9+7;
int n,ans;
struct node{
	int x,y;
}a[maxn];
int f[maxn][maxn];
bool cmp(node a,node b)
{
	return a.y>b.y;
}
int main(){
	freopen("refract.in","r",stdin);
	freopen("refract.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++)
				if((a[k].x<a[i].x&&a[j].x>a[i].x)||(a[k].x>a[i].x&&a[j].x<a[i].x))
					f[i][j]+=f[j][k];
			f[i][j]+=f[j][0];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			ans+=f[i][j];
	printf("%d",ans);
	return 0;
}
