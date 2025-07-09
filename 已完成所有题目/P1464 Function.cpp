#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=21;
ll a,b,c,t[maxn][maxn][maxn];
bool book[maxn][maxn][maxn];
ll f(ll x,ll y,ll z)
{
	if(x<=0||y<=0||z<=0)return 1;
	else if(x>20||y>20||z>20)return f(20,20,20);
	if(book[x][y][z])return t[x][y][z];
	book[x][y][z]=1;
	if(x<y&&y<z)return t[x][y][z]=f(x,y,z-1)+f(x,y-1,z-1)-f(x,y-1,z);
	else return t[x][y][z]=f(x-1,y,z)+f(x-1,y-1,z)+f(x-1,y,z-1)-f(x-1,y-1,z-1);
}
int main(){
	while(1){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,f(a,b,c));
	}
	return 0;
}