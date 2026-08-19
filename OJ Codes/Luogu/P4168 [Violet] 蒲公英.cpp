#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int maxn=1e5+10,maxm=210;
int n,m,p,cnt;
int a[maxn],b[maxn],c[maxn];
int L[maxm],R[maxm],pos[maxn],t[maxn],peo[maxm][maxm],book[maxn];//第i块的左端点，右端点和第j个位置所属的块
int sum[maxm][maxn];//前i块数字（离散化的）j的出现次数 
inline int read()
{
	int x=0,sign=1;
	char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())
		if(ch=='-')
			sign=-sign;
	for(;ch<='9'&&ch>='0';ch=getchar())
		x=(x<<3)+(x<<1)+ch-48;
	return x*sign; 
}
inline void init()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
}
inline void lsh()
{
	for(int i=1;i<=n;i++)
		c[i]=b[i]=a[i];
	sort(b+1,b+n+1);
	cnt=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++)
		b[a[i]]=c[i];
}
inline void divide()
{
	p=sqrt(n);
	for(int i=1;i<=p;i++)
		L[i]=(i-1)*p+1,R[i]=i*p;
	if(R[p]!=n)
		p++,L[p]=R[p-1]+1,R[p]=n;
	for(int i=1;i<=p;i++)
		for(int j=L[i];j<=R[i];j++)
			pos[j]=i;	
}
inline void prepare()
{	 
	for(int i=1;i<=p;i++)
		for(int j=L[i];j<=R[i];j++)
			sum[i][a[j]]++;
	for(int i=2;i<=p;i++)
		for(int j=1;j<=cnt;j++)
			sum[i][j]+=sum[i-1][j];
	for(int i=1;i<=p;i++)
	{
		for(int j=i;j<=p;j++)
		{
			int Max=0;
			/*for(int k=L[i];k<=R[j];k++)
			{
				if(Max<sum[j][a[k]]-sum[i-1][a[k]])
					Max=sum[j][a[k]]-sum[i-1][a[k]],
					peo[i][j]=a[k];
				else if(Max==sum[j][a[k]]-sum[i-1][a[k]]&&a[k]<peo[i][j])
					peo[i][j]=a[k]; 
			}*/
			for(int k=1;k<=cnt;k++)
			{
				if(Max<sum[j][k]-sum[i-1][k])
					Max=sum[j][k]-sum[i-1][k],
					peo[i][j]=k;
			}
		}	
	}	
}
int ask(int l,int r)
{
	if(pos[r]-pos[l]<=2)
	{
		for(int i=l;i<=r;i++)
		t[a[i]]++;
		int Max=0,ans=0;
		for(int i=1;i<=n;i++)
		if(t[i]>Max)Max=t[i],ans=i;
		for(int i=l;i<=r;i++)
		t[a[i]]=0;
		return b[ans];
	}
	else {
		int tmp=peo[pos[l]+1][pos[r]-1];
		for(int i=l;i<=R[pos[l]];i++){
			t[a[i]]++;
		}
		for(int i=L[pos[r]];i<=r;i++){
			t[a[i]]++;
		}
		for(int i=1;i<=cnt;i++){
			if(t[i]!=0){
				t[i]+=sum[pos[r]-1][i]-sum[pos[l]][i];
			}
		}
		if(t[tmp]==0)t[tmp]=sum[pos[r]-1][tmp]-sum[pos[l]][tmp];
		int ans=0,Maxcnt=0;
		for(int i=1;i<=cnt;i++){
			if(t[i]>Maxcnt){
				Maxcnt=t[i];
				ans=i;
			}
		}
		for(int i=l;i<=R[pos[l]];i++)
		t[a[i]]=0,book[a[i]]=0;
		for(int i=L[pos[r]];i<=r;i++)
		t[a[i]]=0,book[a[i]]=0;
		book[tmp]=t[tmp]=0;
		return b[ans];
	}
}
void work()
{
	int ans=0,l0=0,r0=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l0,&r0);
		int l=(l0+ans-1)%n+1,r=(r0+ans-1)%n+1;
		if(l>r)swap(l,r);
		ans=ask(l,r);
		printf("%d\n",ans);
	}
}
int main(){
	//freopen("P4168_1.in","r",stdin);
	//freopen("ans.txt","w",stdout);
	init();
	lsh();
	divide();
	prepare();
	work();
	return 0;
} 