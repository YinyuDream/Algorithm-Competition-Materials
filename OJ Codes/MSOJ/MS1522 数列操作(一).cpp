#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,tpa,tpb;
long long a[maxn],sta[maxn],stb[maxn],suma[maxn],sumb[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),
		sta[++tpa]=a[i],
		suma[tpa]=suma[tpa-1]+sta[tpa];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int opt;
		long long x;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%lld",&x);
			sta[++tpa]=x;
			suma[tpa]=suma[tpa-1]+sta[tpa];
		}else if(opt==2){
			if(tpa!=0)
				tpa--;
		}else if(opt==3){
			if(tpa!=0)
			stb[++tpb]=sta[tpa],
			sumb[tpb]=sumb[tpb-1]+stb[tpb],
			tpa--;
			else continue;
		}else if(opt==4){
			if(tpb!=0)
			sta[++tpa]=stb[tpb],
			suma[tpa]=suma[tpa-1]+sta[tpa],
			tpb--;
			else continue;
		}else if(opt==5){
			scanf("%lld",&x);
			if(x<=tpa)printf("%lld\n",suma[x]);
			else printf("%lld\n",suma[tpa]+(sumb[tpb]-sumb[tpb-(x-tpa)]));
		}
	}
	return 0;
}
