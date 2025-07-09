#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
int x1,x2,x3,__y11,y2,y3;
int dis(int x1,int __y11,int x2,int y2)
{
	return abs(x1-x2)+abs(__y11-y2);
}
signed main(){
	scanf("%lld%lld%lld%lld%lld%lld",&x1,&__y11,&x2,&y2,&x3,&y3);
	printf("%lld",min(min(dis(x1,__y11,x2,y2)+dis(x1,__y11,x3,y3),dis(x1,__y11,x3,y3)+dis(x2,y2,x3,y3)),dis(x1,__y11,x2,y2)+dis(x2,y2,x3,y3)));
	return 0;
}