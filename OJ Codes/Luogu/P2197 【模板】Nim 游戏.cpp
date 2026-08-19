#include<cstdio>
using namespace std;
int T,n,num,t;
int main(){
	scanf("%d",&T);
	while(T--)
	{
		num=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			num^=t;
		}
		printf("%s\n",num?"Yes":"No");
	}
	return 0;
}
