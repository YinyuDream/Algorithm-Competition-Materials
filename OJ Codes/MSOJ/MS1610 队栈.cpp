#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e7+10;
int n,q,p=1;
int a[maxn],b[maxn],c[maxn],top,back,front=1;
char opt[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	scanf("\n%s",opt+1);
	for(int i=1;i<=q;i++)
	{
		if(opt[i]=='1'){
			b[++back]=a[p++];
			if(p==n+1)p=1;
		}else if(opt[i]=='2'){
			c[++top]=b[front++];
		}else if(opt[i]=='3'){
			c[++top]=b[back--];
		}else{
			int t=1;
			while(t<top&&c[t]==0)t++;
			for(int j=t;j<=top;j++)
			printf("%d",c[j]);
			top=0;
			puts("");
		}
	}
	return 0;
}