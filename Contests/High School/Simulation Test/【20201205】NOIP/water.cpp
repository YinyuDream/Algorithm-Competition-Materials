#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1e5+10;
int n,m;
struct nde{
	int to,next;
}e[maxn*5];
int head[maxn],k=0,ru[maxn];
void add(int x,int y){
	e[++k].next=head[x];
	e[k].to=y;
	head[x]=k;
}
inline int read(){
	int sm=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		sm=sm*10-'0'+ch;
		ch=getchar();
	}
	return sm;
}
long long ans1[maxn],ans2[maxn];
bool book[maxn];
int dis[maxn];
struct node{
	int id,dis;
};
bool operator <(const node &x,const node &y){
	return x.dis<y.dis;
}
priority_queue<node>Q;
long long gcd(long long a,long long b){
	if(!b) return a;
	return gcd(b,a%b);
}
void bfs(){
	for(int i=1;i<=m;i++){
		ans1[i]=1;
		Q.push((node){i,dis[i]});
	}
	while(!Q.empty()){
		int id=Q.top().id;
		Q.pop();
		if(!ru[id]||!ans1[id]) continue;
		long long sum=ans1[id];
		long long num=ans2[id]*ru[id];
		long long gc=gcd(sum,num);
		if(gc>1){
			sum/=gc;
			num/=gc;	
		}
		for(int i=head[id];i;i=e[i].next){
			int tp=e[i].to;
			ans1[tp]=ans1[tp]*num+sum*ans2[tp];
			ans2[tp]*=num;
			gc=gcd(ans1[tp],ans2[tp]);
			if(gc>1){
				ans1[tp]/=gc;
				ans2[tp]/=gc;	
			}
			Q.push((node){tp,dis[tp]});
		}
		ans1[id]=0;
	}
}
void dfs(int id){
	if(dis[id]) return;
	dis[id]=1;
	for(int i=head[id];i;i=e[i].next){
		int tp=e[i].to;
		dfs(tp);
		dis[id]+=dis[tp];
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	int a;
	for(int i=1;i<=n;i++){
		ru[i]=read();
		ans2[i]=1;
		for(int j=1;j<=ru[i];j++){
			a=read();
			add(i,a);
		}
	}
	for(int i=1;i<=m;i++) dfs(i);
	bfs();
	for(int i=1;i<=n;i++){
		if(ru[i]) continue;
		printf("%lld %lld\n",ans1[i],ans2[i]);
	}
	return 0;
}
