#include<cstdio>
#include<queue>
#define int long long  
using namespace std;
const int maxn=1e6+10;
int m;
int money,use,cnt;
int ice[maxn]; 
signed main()
{
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		int opt,a,b;
		scanf("%lld",&opt);
		if(ice[i])use+=ice[i],ice[i]=0;
		if(opt==1)scanf("%lld",&a),use+=a; 	
		else if(opt==2)
		{
			scanf("%lld",&a);
			if(use-a>=0)use-=a;
			else cnt++;
		}
		else if(opt==3)
		{
			scanf("%lld%lld",&a,&b);
			use-=a;
			ice[b]+=a;
		} 
		//printf("%d\n",use);
	}
	printf("%lld",cnt);
	return 0;
 } 
