#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	for(int i=1,ax,ay,bx,by;i<=T;i++)
	{
		scanf("%d%d%d%d",&ax,&ay,&bx,&by);
		printf("%s\n",__gcd(abs(bx-ax),abs(by-ay))==1?"no":"yes");
	}
	return 0;
}
