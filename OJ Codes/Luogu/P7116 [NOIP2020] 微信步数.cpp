#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=5e5+10;
int n,m,w[20];
inline int read(){
	int sm=0,naga=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') naga=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sm=sm*10-'0'+ch;
		ch=getchar();
	}
	if(naga) return sm;
	return -sm;
}
struct node{
	int a,b;
}h[maxn];
int mx[20],mn[20],sum[20],qi[20],tmp[20];
long long ans=0;
void dfs(int wei){
	if(wei>m){
		for(int i=1;i<=m;i++) tmp[i]=qi[i];
		bool flag=1;
		while(flag){
			for(int i=1;i<=m;i++) if(tmp[i]+mx[i]>w[i]||tmp[i]+mn[i]<1) flag=0;
			if(!flag) break;
			ans+=n;
			for(int i=1;i<=m;i++) tmp[i]+=sum[i];
		}
		for(int i=1;1;){
			tmp[h[i].a]+=h[i].b;
			ans++;
			if(tmp[h[i].a]==0||tmp[h[i].a]>w[h[i].a]) return;
			if(i==n) i=1;
			else i++;
		}
	}
	for(int i=1;i<=w[wei];i++){
		qi[wei]=i;
		dfs(wei+1);
	}
}
int main(){
	//freopen("walk.in","r",stdin);
	//freopen("walk.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=m;i++) sum[i]=mn[i]=mx[i]=0;
	for(int i=1;i<=n;i++){
		h[i].a=read();h[i].b=read();
		sum[h[i].a]+=h[i].b;
		mn[h[i].a]=min(mn[h[i].a],sum[h[i].a]);
		mx[h[i].a]=max(mx[h[i].a],sum[h[i].a]);
	}
	bool flag=0;
	for(int i=1;i<=m;i++){
		if(sum[i]!=0){
			flag=1;
			break;
		}
		if(mx[i]+(mx[i]>0)-mn[i]+(mn[i]<0)>w[i]){
			flag=1;
			break;
		}
	}
	if(!flag){
		printf("-1");
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}