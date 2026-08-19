#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,ans;
int p[maxn],book[maxn],mxx[maxn],mnx[maxn],mxy[maxn],mny[maxn],sum[maxn],flag[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x; 
}
int main(){
	memset(mnx,0x3f,sizeof mnx);
	memset(mny,0x3f,sizeof mny);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			p[i*(m+5)+j]=read();
			book[p[i*(m+5)+j]]++;
			mxx[p[i*(m+5)+j]]=max(mxx[p[i*(m+5)+j]],i);
			mnx[p[i*(m+5)+j]]=min(mnx[p[i*(m+5)+j]],i);
			mxy[p[i*(m+5)+j]]=max(mxy[p[i*(m+5)+j]],j);
			mny[p[i*(m+5)+j]]=min(mny[p[i*(m+5)+j]],j);
		}
	}
	for(int i=1;i<=k;i++){
		if(!book[i])continue;
		sum[mnx[i]*(m+5)+mny[i]]++;
		sum[mnx[i]*(m+5)+mxy[i]+1]--;
		sum[(mxx[i]+1)*(m+5)+mny[i]]--;
		sum[(mxx[i]+1)*(m+5)+mxy[i]+1]++;
	}
	for(int i=1;i<=k;i++)
		if(!book[i])
			ans++;
	if(ans==k-1)return printf("%d\n",ans),0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i*(m+5)+j]+=sum[(i-1)*(m+5)+j]+sum[i*(m+5)+j-1]-sum[(i-1)*(m+5)+j-1];
			if(sum[i*(m+5)+j]>1)
				flag[p[i*(m+5)+j]]=1;
		}
	}
	for(int i=1;i<=k;i++)
		if(book[i]&&!flag[i])
			ans++;
	printf("%d",ans); 
	return 0;
}
