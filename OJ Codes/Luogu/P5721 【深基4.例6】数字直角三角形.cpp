#include<cstdio>
using namespace std;
int n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(++cnt<=9)printf("0");
			printf("%d",cnt);
		}
		puts("");
	}
	return 0;
}
