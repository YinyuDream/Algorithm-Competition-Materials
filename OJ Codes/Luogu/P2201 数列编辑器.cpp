#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,tpa,tpb;
long long a[maxn],sta[maxn],stb[maxn],suma[maxn],maxx[maxn];
int main(){
	maxx[0]=-0x7f7f7f7f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char opt;
		long long x;
		scanf("\n%c",&opt);
		if(opt=='I'){
			scanf("%lld",&x);
			sta[++tpa]=x;
			suma[tpa]=suma[tpa-1]+sta[tpa];
			maxx[tpa]=max(maxx[tpa-1],suma[tpa]);
		}else if(opt=='D'){
			if(tpa!=0)
				tpa--;
		}else if(opt=='L'){
			if(tpa==0)continue;
			stb[++tpb]=sta[tpa];
			tpa--;
		}else if(opt=='R'){
			if(tpb==0)continue;
			sta[++tpa]=stb[tpb];
			suma[tpa]=suma[tpa-1]+sta[tpa];
			maxx[tpa]=max(maxx[tpa-1],suma[tpa]);
			tpb--;
		}else{
			scanf("%lld",&x);
			printf("%lld\n",maxx[x]);
		}
	}
	return 0;
}
