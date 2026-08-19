#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,p,top,cnt,last_ans;
int st_id[maxn],st_w[maxn];
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		char opt;int x;
		scanf("\n%c %d",&opt,&x);
		if(opt=='Q')
		printf("%d\n",last_ans=st_w[lower_bound(st_id+1,st_id+top+1,cnt-x+1)-st_id]);
		else{
			x=(x+last_ans)%p,cnt++;
			while(top&&st_w[top]<=x)top--;
			st_w[++top]=x,st_id[top]=cnt;
		}
	}
	return 0;
}
