#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5010;
int n=1;
struct node{
	int l,r,h;
}a[maxn];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main(){
	while(scanf("%d%d%d",&a[n].l,&a[n].r,&a[n].h)!=EOF)n++;
	n--;
	sort(a+1,a+n+1,cmp);
	return 0;
} 
