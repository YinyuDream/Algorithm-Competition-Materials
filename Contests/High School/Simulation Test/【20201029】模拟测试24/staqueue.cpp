#include<cstdio>
using namespace std;
const int maxn=2e7+10;
int n,q,p=1;
int a[maxn];
char opt[maxn];
int que[maxn],head=1,tail;
int que2[maxn],head2=1,tail2;
int main(){
	freopen("staqueue.in","r",stdin);
	freopen("staqueue.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d\n%s",&q,opt+1);
	for(int i=1;i<=q;i++){
		if(opt[i]=='1'){
			que[++tail]=a[p++];
			if(p==n+1)p=1;
		}else if(opt[i]=='2'){
			que2[++tail2]=que[head++];
		}else if(opt[i]=='3'){
			que2[++tail2]=que[tail--];
		}else{
			while(head2<tail2&&que2[head2]==0)head2++;
			while(head2<=tail2)printf("%d",que2[head2++]);
			puts("");
		}
	}
	return 0;
}
