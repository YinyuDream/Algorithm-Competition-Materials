#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=4e7+10;
int n,m;
long long _z,_p;
int nextn[maxn],extend[maxn];
char z[maxn],p[maxn];
void get_next()
{
	nextn[0]=m;
	int now=0;
	while(p[now]==p[now+1]&&now+1<m)
	now++;
	nextn[1]=now;
	int pt=1;
	for(int i=2;i<m;i++)
	{
		if(i+nextn[i-pt]<nextn[pt]+pt)nextn[i]=nextn[i-pt];
		else{
			now=nextn[pt]+pt-i;
			now=max(now,0);
			while(p[now]==p[i+now]&&i+now<m)now++;
			nextn[i]=now;
			pt=i;
		}
	}
}
void ex_kmp()
{
	int now=0;
	while(z[now]==p[now]&&now<min(n,m))now++;
	extend[0]=now;
	int pt=0;
	for(int i=1;i<n;i++)
	{
		if(i+nextn[i-pt]<extend[pt]+pt)extend[i]=nextn[i-pt];
		else{
			now=extend[pt]+pt-i;
			now=max(now,0);
			while(p[now]==z[i+now]&&now<m&&i+now<n)now++;
			extend[i]=now;
			pt=i;
		}
	}
}
int main(){
	scanf("%s\n%s",z,p);
	n=strlen(z),m=strlen(p);
	get_next();
	ex_kmp();
	for(int i=0;i<m;i++)
		_z^=1ll*(i+1)*(nextn[i]+1);
	for(int i=0;i<n;i++)
		_p^=1ll*(i+1)*(extend[i]+1);
	printf("%lld\n%lld",_z,_p);
	return 0;
}
