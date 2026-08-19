#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int main(){
	//freopen("deposit.in","r",stdin);
	//freopen("deposit.out","w",stdout);
	scanf("%d",&T);
	for(int i=1,a,b,c,d,x,y,dx,dy;i<=T;i++){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y);
		dx=abs(c-a),dy=abs(d-b);
		if(dx%x==0&&dy%y==0&&(dx/x+dy/y)%2==0)puts("YES");
		else puts("NO");
	}
	return 0;
}