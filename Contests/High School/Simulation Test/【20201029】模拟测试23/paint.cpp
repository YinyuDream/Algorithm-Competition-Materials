#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,ans;
int p[maxn],book[maxn],mxx[maxn],mnx[maxn],mxy[maxn],mny[maxn],flag[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x; 
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	memset(mnx,0x3f,sizeof mnx);
	memset(mny,0x3f,sizeof mny);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			p[(i-1)*m+j]=read();
			book[p[(i-1)*m+j]]++;
			mxx[p[(i-1)*m+j]]=max(mxx[p[(i-1)*m+j]],i);
			mnx[p[(i-1)*m+j]]=min(mnx[p[(i-1)*m+j]],i);
			mxy[p[(i-1)*m+j]]=max(mxy[p[(i-1)*m+j]],j);
			mny[p[(i-1)*m+j]]=min(mny[p[(i-1)*m+j]],j);
		}
	}
	for(int i=1;i<=k;i++)
		if(!book[i])
			ans++;
	for(int i=1;i<=k;i++){
		if(!book[i])continue;
		for(int j=mnx[i];j<=mxx[i];j++){
			for(int k=mny[i];k<=mxy[i];k++){
				if(p[(j-1)*m+k]!=i){
					flag[p[(j-1)*m+k]]=1;
				}
			}
		}
	}
	for(int i=1;i<=k;i++)
		if(book[i]&&!flag[i])
			ans++;
	printf("%d",ans); 
	return 0;
}
