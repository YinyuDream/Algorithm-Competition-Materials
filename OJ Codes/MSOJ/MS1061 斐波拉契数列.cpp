#include<cstdio>
using namespace std;
long long a1=1,a2=1,am,k;
int main(){
	scanf("%d",&k);
	if(k==1)printf("%lld",a1);
	if(k==2)printf("%lld",a2);
	if(k>=3){
	for(int i=3;i<=k;i++)
	{
		am=a1+a2;
		a1=a2;
		a2=am;
	}
	printf("%lld",am);
	}
	return 0;
} 
