#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=5e7+10;
int n,m,cnt,x,y;
ll sum,mul,add;
int a[maxn],flag[maxn];
int read(){
	int x=0,sign=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')sign=-sign;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,
	ch=getchar();
	return x*sign;
}
int main(){
	n=read();m=read();
	mul=1,sum=1ll*n*(n+1)/2,cnt=1;
	for(int i=1;i<=m;i++)
	{
		char opt=getchar();
		while(opt!='A'&&opt!='B')
		opt=getchar();
		x=read(),y=read();
		if(opt=='A'){
			cnt++;mul=x;add=y;
			sum=mul*n*(n+1)/2+add*n;
		}else{
			if(flag[x]==cnt){
				sum+=y-a[x];
				a[x]=y;
			}else{
				sum+=-mul*x+y-add;
				a[x]=y;flag[x]=cnt;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
