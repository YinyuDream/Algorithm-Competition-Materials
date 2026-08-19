#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10,N=1e3+10;
int n,m,block;
int h[maxn],a[maxn],b[maxn];
int l[maxn],r[maxn],pos[maxn];
int num1[N][N],num2[N][N];//1:l->rµÝÔö,2:r->lµÝÔö 
void pre()
{
	block=sqrt(n);
	for(int i=1;i<=block;i++)
	l[i]=(i-1)*block+1,r[i]=i*block;
	if(r[block]!=n)
	block++,l[block]=r[block-1]+1,r[block]=n;
	for(int i=1;i<=block;i++)
	{
		int pt1=0,pt2=0;
		for(int j=l[i];j<=r[i];j++)
		{
			pos[j]=i;
			if(!pt1||h[j]>a[pt1])
			num1[i][++pt1]=h[j];
		}
		for(int j=r[i];j>=l[i];j--)
		{
			if(!pt2||h[j]>b[pt2])
			num2[i][++pt2]=h[j];
		}
		num1[i][0]=pt1;
		num2[i][0]=pt2;
	}
}
void change(int p,int x)
{
	h[p]=x;
	int pt1=0,pt2=0;
	for(int i=l[pos[p]];i<=r[pos[p]];i++)
	{
		if(!pt1||h[i]>a[pt1])
		num1[pos[p]][++pt1]=h[i];
	}
	for(int i=r[pos[p]];i>=l[pos[p]];i--)
	{
		if(!pt2||h[i]>b[pt2])
		num2[pos[p]][++pt2]=h[i];
	}
	num1[pos[p]][0]=pt1;
	num2[pos[p]][0]=pt2;
}
int query(int x)
{
	int pt1=0,pt2=0,tp=h[x];
	h[x]=0;
	for(int i=x;i<=r[pos[x]];i++)
	{
		if(!pt1||h[i]>b[pt1])
			b[++pt1]=h[i];
	}
	for(int i=x;i>=l[pos[x]];i--)
	{
		if(!pt2||h[i]>a[pt2])
			a[++pt2]=h[i];
	}
	//pt1=pt2=0;
	printf("##%d %d\n",pt1,pt2);
	for(int i=pos[x]+1;i<=block;i++)
	{
		int t=lower_bound(num1[i]+1,num1[i]+num1[i][0]+1,i==pos[x]+1?b[pt1]:num1[i-1][num1[i-1][0]])-num1[i];
		//if(t==num1[i][0]+1)t=0;
		printf("!!%d",num1[i][0]-t);
		pt1+=num1[i][0]-t;
	}
	for(int i=pos[x]-1;i>=1;i--)
	{
		int t=lower_bound(num2[i]+1,num2[i]+num2[i][0]+1,i==pos[x]-1?a[pt2]:num2[i+1][num2[i+1][0]])-num2[i];
		//if(t==num2[i][0]+1)t=0;
		printf("!!%d\n",num2[i][0]-t);
		pt2+=num2[i][0]-t;
	}
	h[x]=tp;
	printf("##%d %d\n",pt1,pt2);
	return pt1+pt2-1;	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&h[i]);
	pre();
	for(int i=1;i<=m;i++)
	{
		int opt,p,x;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&p,&x);
			change(p,x);
		}
		else
		{
			scanf("%d",&p);
			printf("%d\n",query(p));
		}
		//debug();
	}
	/*for(int i=1;i<=m;i++)
	{
		int opt,p,x;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&p,&x);
			h[p]=x;
		}
		else
		{
			int cnt=0;
			pt=0;
			scanf("%d",&p);
			for(int j=p-1;j;j--)
			{
				if(pt==0||h[j]>a[pt])
				a[++pt]=h[j];
			}
			cnt+=pt;
			pt=0;
			for(int j=p+1;j<=n;j++)
			{
				if(pt==0||h[j]>a[pt])
				a[++pt]=h[j];
			}
			cnt+=pt;
			printf("%d\n",cnt+1);
		}
	}*/
	
	return 0;
}
