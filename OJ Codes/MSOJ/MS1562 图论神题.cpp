#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5e6+10;
int n,m;
int w[maxn];
long long ans;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0,sign=1;
    while(!(ch>='0'&&ch<='9')){
    	if(ch=='-')sign=-sign;
    	ch=nc();
    }
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum*sign;
}
void write(long long x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		w[i]=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		ans+=min(w[u],w[v]);
	}
	write(ans);
	return 0;
}