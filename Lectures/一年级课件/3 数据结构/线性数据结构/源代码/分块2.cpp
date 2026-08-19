/*
8
13 2 7 3 5 4 6 4
2 1 8 5
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50000+10;
int L[maxn],R[maxn],pos[maxn],add[maxn];//pos[i]=j表示第i个元素所属快j
int a[maxn];
int n,t,k;
inline void update(int x,int y,int val){
	int p=pos[x],q=pos[y];
	if(p==q){//在同一块内，暴力处理 
		for(int i=x;i<=y;i++) a[i]+=val;
		sort(a+L[p],a+R[q]+1);
	} else {
		for(int i=p+1;i<=q-1;i++) add[i]+=val;//完整块处理 
		for(int i=x;i<=R[p];i++) a[i]+=val;//非完整块前半部分处理
		for(int i=L[q];i<=y;i++) a[i]+=val;//非完整块后半部分处理
		sort(a+L[p],a+R[p]+1);
		sort(a+L[q],a+R[q]+1); 
	}
}
inline int query(int x,int y,int val){
	int ans=0,p=pos[x],q=pos[y];
	//printf("%d %d\n",p,q);
	if(p==q){
		for(int i=x;i<=y;i++) if(a[i]<val-add[p]) ans++;
		return ans;
	}
	for(int i=p+1;i<=q-1;i++){//完整块处理,二分查找 
		int s=lower_bound(a+L[i],a+R[i]+1,val-add[i])-a; 
		printf("%d %d\n",s,s-L[i]);
		ans+=(s-L[i]);
	}
	for(int i=x;i<=R[p];i++) if(a[i]<val-add[p]) ans++;
	for(int i=L[q];i<=y;i++) if(a[i]<val-add[q]) ans++;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	t=sqrt(n);
	for(int i=1;i<=t;i++){
		L[i]=(i-1)*t+1;
		R[i]=i*t;
		sort(a+L[i],a+R[i]+1);
	}
	if(R[t]<n){
		t++;
		L[t]=R[t-1]+1; R[t]=n;
		sort(a+L[t],a+R[t]+1);
	}
	for(int i=1;i<=t;i++){
		printf("第%d块：",i);
		for(int j=L[i];j<=R[i];j++) pos[j]=i,printf("%d ",a[j]);
		printf("\n");
	}
	for(int i=1;i<=n;i++){
		int opt,x,y,val;
		scanf("%d%d%d%d",&opt,&x,&y,&val);
		if(opt==1) update(x,y,val); //区间加
		if(opt==2) printf("%d\n",query(x,y,val)); //区间查询 
	}
	return 0;
}
