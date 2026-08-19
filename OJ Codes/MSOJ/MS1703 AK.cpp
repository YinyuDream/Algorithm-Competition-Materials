#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,h,pos,val,ans;
struct node{
	int a,b;
}p[maxn];
int sum[maxn],f[maxn];
bool cmp(node x,node y)
{
	return x.a+x.b<y.a+y.b;
}
int main(){
	memset(f,-0x3f,sizeof f);
	f[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].b),f[0]+=p[i].a;
	scanf("%d",&h);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(f[j-1]+p[i].b>=h){
				f[j]=max(f[j],f[j-1]-p[i].a);
			}
		}
	}
	for(int i=n;i>=0;i--)
		if(f[i]>=0)
			return printf("%d",i),0;
	return 0;
}