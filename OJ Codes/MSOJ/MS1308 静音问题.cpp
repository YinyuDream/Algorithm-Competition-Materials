#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e6+10;
int n,m,c,p;
int a[maxn],mx[maxn],minx[maxn];
int q[maxn*3],head,tail;
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(head<tail&&q[head]<i-m+1)head++;
		while(head<tail&&a[q[tail-1]]<a[i])tail--;
		q[tail++]=i;
		mx[i]=a[q[head]];
	}
	head=0,tail=0;
	for(int i=1;i<=n;i++){
		if(head<tail&&q[head]<i-m+1)head++;
		while(head<tail&&a[q[tail-1]]>a[i])tail--;
		q[tail++]=i;
		minx[i]=a[q[head]];
	}
	for(int i=m;i<=n;i++)
		if(mx[i]-minx[i]<=c)printf("%d\n",i-m+1),p=1;
	if(!p)puts("NONE");
	return 0;
}