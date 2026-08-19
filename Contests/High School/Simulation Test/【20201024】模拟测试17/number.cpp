#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int T,l,r;
int a[maxn];
bool check(int x)
{
	int top=0;
	while(x){
		a[++top]=x%9;
		x/=9;
	}
	for(int i=1;i<=(top+1)/2;i++)
		if(a[i]!=a[top-i+1])
			return false;
	return true;
}
int solve(int l,int r)
{
	int ans=0;
	for(int i=l;i<=r;i++)
		ans+=check(i);
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r));
	}
	return 0;
}
