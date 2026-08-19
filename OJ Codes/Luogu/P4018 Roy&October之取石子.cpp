#include<cstdio>
using namespace std;
int n,T;
int main(){
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%s\n",n%6?"October wins!":"Roy wins!");
	}
}
