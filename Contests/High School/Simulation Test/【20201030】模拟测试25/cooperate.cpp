#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=15;
int T,n,k,top;
int a[maxn],mx[maxn],mn[maxn];
void work(int x)
{
	top=0;
	while(x){
		a[++top]=x%10;
		x/=10;
	}
	reverse(a+1,a+top+1);
}
int find_max(int pos)
{
	int st=pos;
	for(int i=top;i>=st+1;i--)
		if(mx[i]>mx[pos])
			pos=i;
	return pos;
}
int find_min(int pos,int opt)
{
	int st=pos;
	for(int i=top;i>=st+1;i--)
		if(mn[i]<mn[pos]&&(opt?mn[i]!=0:1))
			pos=i;
	return pos;
}
int get_max()
{
	int sum=0,cnt=0;
	for(int i=1;i<=top;i++)
		mx[i]=a[i];
	for(int i=1;i<=top&&cnt<k;i++){
		int t=find_max(i);
		if(t==i)continue;
		swap(mx[i],mx[t]);
		cnt++;
	}
	for(int i=1;i<=top;i++)
		sum=sum*10+mx[i];
	return sum;
}
int get_min()
{
	int sum=0,cnt=0,opt=1;
	for(int i=1;i<=top;i++)
		mn[i]=a[i];
	for(int i=1;i<=top&&cnt<k;i++){
		if(mn[i]==0)opt=0;
		int t=find_min(i,opt);
		if(t==i)continue;
		swap(mn[i],mn[t]);
		cnt++;
	}
	for(int i=1;i<=top;i++)
		sum=sum*10+mn[i];
	return sum;
}
int main(){
	freopen("cooperate.in","r",stdin);
	freopen("cooperate.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		work(n);
		printf("%d\n",get_max()-get_min());
	}
	return 0;
}
