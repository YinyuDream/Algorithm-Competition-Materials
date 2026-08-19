#include<cmath>
#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,block;
int a[maxn],belong[maxn],l[maxn],r[maxn],num[maxn],nextn[maxn];
void pre()
{
	for(int i=1;i<=block;i++)
	l[i]=(i-1)*block+1,r[i]=i*block;
	if(r[block]!=n)block++,l[block]=r[block-1]+1,r[block]=n;
	for(int i=1;i<=block;i++)
		for(int j=l[i];j<=r[i];j++)
			belong[j]=i;
	for(int i=n;i>=1;i--)
		if(i+a[i]<=n&&belong[i]==belong[i+a[i]])nextn[i]=nextn[i+a[i]],num[i]=num[i+a[i]]+1;
		else if(i+a[i]<=n&&belong[i]!=belong[i+a[i]])nextn[i]=i+a[i],num[i]=1;
		else num[i]=1,nextn[i]=0;
}
void update(int pos,int val)
{
	a[pos]=val;
	for(int i=r[belong[pos]];i>=l[belong[pos]];i--){
		if(i+a[i]<=n&&belong[i]==belong[i+a[i]])nextn[i]=nextn[i+a[i]],num[i]=num[i+a[i]]+1;
		else if(i+a[i]<=n&&belong[i]!=belong[i+a[i]])nextn[i]=i+a[i],num[i]=1;
		else num[i]=1,nextn[i]=0;
	}
}
int query(int pos)
{
	int cnt=0;
	while(pos){
		cnt+=num[pos];
		pos=nextn[pos];
	}
	return cnt;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	block=sqrt(n);
	pre();
	scanf("%d",&m);
	for(int i=1,opt,x,y;i<=m;i++){
		scanf("%d%d",&opt,&x);
		if(opt==1)printf("%d\n",query(++x));
		else scanf("%d",&y),update(++x,y);
	}
	return 0;
}
