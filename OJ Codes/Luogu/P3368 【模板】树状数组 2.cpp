#include<cstdio>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],b[maxn],tree[maxn];
void update(int x,int val){
	while(x<=n)tree[x]+=val,x+=(x&-x);
}
int deqre(int x){
	int ans=0;
	while(x>0)ans+=tree[x],x-=(x&-x);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i]-a[i-1],update(i,b[i]);
	for(int i=1,opt,x,y,k;i<=m;i++){
		scanf("%d",&opt);
		if(opt==1)scanf("%d%d%d",&x,&y,&k),update(x,k),update(y+1,-k);
		if(opt==2)scanf("%d",&x),printf("%d\n",deqre(x));
	}
	return 0;
}