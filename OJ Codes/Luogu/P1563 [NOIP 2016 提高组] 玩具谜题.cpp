#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,now=1;
int face[maxn];
char job[maxn][12];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%s",&face[i],job[i]);
	for(int i=1;i<=m;i++)
	{
		int opt,s;
		scanf("%d%d",&opt,&s);
		int t=opt^face[now];
		if(t==1){
			now=now+s;
			if(now>n)now-=n;
		}else{
			now=now-s;
			if(now<=0)now+=n;
		}
	}
	printf("%s\n",job[now]);
}
