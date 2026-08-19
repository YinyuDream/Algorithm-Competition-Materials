#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5e3+10;
int n,k,x,y,t;
char a[maxn];
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%s\n%d",a+1,&k);
	n=strlen(a+1);
	for(int i=1;i<=min(n,k);i++){
		if(a[i]=='E')x++;
		else if(a[i]=='W')x--;
		else if(a[i]=='N')y++;
		else y--;
	}
	t=k/n,x*=t,y*=t,k%=n;
	for(int i=1;i<=k;i++){
		if(a[i]=='E')x++;
		else if(a[i]=='W')x--;
		else if(a[i]=='N')y++;
		else y--;
	}
	printf("%d %d\n",x,y);
	return 0;
}
