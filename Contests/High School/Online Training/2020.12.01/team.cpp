#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2e3+10;
int n,m;
int a[maxn],book[maxn];
int query(int l,int r)
{
	int ans=0;
	for(int i=l;i<=r;i++){
		memset(book,0,sizeof book);
		for(int j=i;j<=r;j++){
			if(!book[a[j]]){
				book[a[j]]++;
				ans++;
			}else break;
		}
	}
	return ans;
}
int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,opt,x,y;i<=m;i++){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)a[x]=y;
		else printf("%d\n",query(x,y));
	}
	return 0;
}
