#include<cstdio>
using namespace std;
int n;
double p,ans,len;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&p);
		ans=ans-len*len*len+((len+1)*p)*((len+1)*p)*((len+1)*p);
		len=(len+1)*p;
	}
	printf("%lf",ans);
	return 0;
}
