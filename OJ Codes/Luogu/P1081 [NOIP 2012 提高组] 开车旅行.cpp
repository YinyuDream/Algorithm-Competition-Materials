#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+10,inf=0x7f7f7f7f;
int n,m,ans,x0;
double _ans=inf;
int pos[maxn],nextn[maxn],next2[maxn],dis[maxn],dis2[maxn];
int f[maxn][20],g[maxn][20],g2[maxn][20];
struct node{
	int h,id,l,r;
}a[maxn];
struct point{
	int num,id;
	point(){}
	point(int _num,int _id){
		num=_num,id=_id;
	}
}b[5];
bool cmp(node a,node b)
{
	return a.h<b.h;
}
bool cmps(point _a,point _b)
{
	if(_a.num!=_b.num)return _a.num<_b.num;
	else return a[pos[_a.id]].h<a[pos[_b.id]].h;
}
void calc(int st,int d,int &x,int &y)
{
	for(int i=19;i>=0;i--)
		if(f[st][i]&&x+y+g[st][i]+g2[st][i]<=d)
			x+=g[st][i],y+=g2[st][i],st=f[st][i];	
}
int main(){
	//freopen("drive.in","r",stdin);
	//freopen("drive.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].h),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		pos[a[i].id]=i,a[i].l=i-1,a[i].r=i+1;
	a[0].h=a[n+1].h=inf;
	for(int i=1;i<=n;i++)
	{
		node t1=a[a[pos[i]].l],t2=a[a[pos[i]].r],t3=a[a[a[pos[i]].l].l],t4=a[a[a[pos[i]].r].r];
		b[1]=point(abs(t1.h-a[pos[i]].h),t1.id);
		b[2]=point(abs(t2.h-a[pos[i]].h),t2.id);
		b[3]=point(abs(t3.h-a[pos[i]].h),t3.id);
		b[4]=point(abs(t4.h-a[pos[i]].h),t4.id);
		sort(b+1,b+5,cmps);
		nextn[i]=b[1].id;next2[i]=b[2].id;dis[i]=b[1].num;dis2[i]=b[2].num;
		a[a[pos[i]].l].r=a[pos[i]].r;
		a[a[pos[i]].r].l=a[pos[i]].l;
	}
	dis[n]=dis2[n]=next2[n]=dis2[n-1]=next2[n-1]=0;
	for(int i=1;i<n;i++)
		f[i][0]=next2[i],
		g[i][0]=dis2[i];
	for(int i=1;i<=n;i++){
		f[i][1]=nextn[f[i][0]];
		if(f[i][1])
		g[i][1]=g[i][0],g2[i][1]=dis[f[i][0]];
	}
	for(int i=2;i<=19;i++)
		for(int j=1;j<=n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
			if(f[j][i])
			g[j][i]=g[f[j][i-1]][i-1]+g[j][i-1],
			g2[j][i]=g2[f[j][i-1]][i-1]+g2[j][i-1];
		}
	scanf("%d%d",&x0,&m);
	for(int i=1;i<=n;i++)
	{
		int x=0,y=0;
		calc(i,x0,x,y);
		if(y==0)continue;
		if(_ans>1.0*x/y)_ans=1.0*x/y,ans=i;
		else if(_ans==1.0*x/y&&a[pos[ans]].h<a[pos[i]].h)ans=i;
	}
	printf("%d\n",ans);
	for(int i=1,s;i<=m;i++)
	{
		int x=0,y=0;
		scanf("%d%d",&s,&x0);
		calc(s,x0,x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}