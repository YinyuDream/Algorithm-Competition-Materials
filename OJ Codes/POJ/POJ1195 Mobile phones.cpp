#include<cstdio>
#define int long long
using namespace std;
const int maxn=(1<<10)+5;
int tree[maxn][maxn];
int s;
inline int lowbit(int x)
{
	return x&-x;
}
void update(int x,int y,int val)
{
	for(int i=x;i<=s;i+=lowbit(i))
	for(int j=y;j<=s;j+=lowbit(j))
	tree[i][j]+=val;
}
int ask(int x,int y)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	for(int j=y;j>0;j-=lowbit(j))
	sum+=tree[i][j];
	return sum;
}
signed main(){
	int opt;
	scanf("%lld%lld",&opt,&s);
	while(1)
	{
		scanf("%lld",&opt);
		if(opt==1){
			int x,y,a;
			scanf("%lld%lld%lld",&x,&y,&a);
			x++,y++;
			update(x,y,a);
		}else if(opt==2){
			int l,b,r,t;
			scanf("%lld%lld%lld%lld",&l,&b,&r,&t);
			l++,r++,b++,t++;
			printf("%lld\n",ask(r,t)-ask(l-1,t)-ask(r,b-1)+ask(l-1,b-1));
		}else break;
	}
	return 0;
}