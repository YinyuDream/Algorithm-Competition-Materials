#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef vector<int>::iterator IT;
const int maxn=1e5+10;
int T,n;
vector<int>bkx[maxn],bky[maxn];
struct node{
	int x,y;
}p[maxn];
bool cmp(node a,node b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}
void lsh()
{
	static int help[maxn];
	for(int i=1;i<=n;i++)
		help[i]=p[i].x;
	sort(help+1,help+n+1);
	int cnt=unique(help+1,help+n+1)-help-1;
	for(int i=1;i<=n;i++)
		p[i].x=lower_bound(help+1,help+cnt+1,p[i].x)-help;
	for(int i=1;i<=n;i++)
		help[i]=p[i].y;
	sort(help+1,help+n+1);
	cnt=unique(help+1,help+n+1)-help-1;
	for(int i=1;i<=n;i++)
		p[i].y=lower_bound(help+1,help+cnt+1,p[i].y)-help;
}
bool work(int x,int y,int face,int limit)
{
	int cnt=0;
	while(cnt<=limit)
	{
		if(face==0){
			IT t=upper_bound(bkx[y].begin(),bkx[y].end(),x);
			if(t==bkx[y].end())return true;
			x=*t;
			face++;
		}else if(face==1){
			IT t=upper_bound(bky[x].begin(),bky[x].end(),y);
			if(t==bky[x].end())return true;
			y=*t;
			face++;
		}else if(face==2){
			IT t=lower_bound(bkx[y].begin(),bkx[y].end(),x);
			if(t==bkx[y].begin())return true;
			x=*(t-1);
			face++;
		}else{
			IT t=lower_bound(bky[x].begin(),bky[x].end(),y);
			if(t==bky[x].begin())return true;
			y=*(t-1);
			face=0;
		}
		cnt++;
	}
	return false;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int x,y,dx,dy,face;
		scanf("%d%d%d%d%d",&x,&y,&dx,&dy,&n);
		if(dx==1&&dy==0)face=0;
		else if(dx==0&&dy==1)face=1;
		else if(dx==-1&&dy==0)face=2;
		else face=3;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		p[++n].x=x,p[n].y=y;
		lsh();
		sort(p+1,p+n,cmp);
		for(int i=0;i<maxn;i++){
			bkx[i].clear();
			bky[i].clear();
		}
		for(int i=1;i<n;i++){
			bkx[p[i].x].push_back(p[i].y);
			bky[p[i].y].push_back(p[i].x);
		}
		if(work(p[n].x,p[n].y,face,(n-1)*4))puts("YES");
		else puts("NO");
	}
	return 0;
}
