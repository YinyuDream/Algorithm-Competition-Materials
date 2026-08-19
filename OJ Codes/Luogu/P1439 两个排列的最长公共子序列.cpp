#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn],b[maxn],pos[maxn];
int st[maxn],top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),
		pos[b[i]]=i;
	for(int i=1;i<=n;i++)
	{
		if(!top||pos[a[i]]>st[top])
		st[++top]=pos[a[i]];
		else st[lower_bound(st+1,st+top+1,pos[a[i]])-st]=pos[a[i]];
	}
	printf("%d",top);
	return 0;
}
