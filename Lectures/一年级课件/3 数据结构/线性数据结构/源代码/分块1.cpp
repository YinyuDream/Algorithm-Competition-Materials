/*
分块1：区间修改，单点查询,opt=0表示修改，opt=1表示查询 
5 6
1 5 6 8 9
1 3
0 3 5 2
0 1 4 3
1 3
1 1
1 4
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=100000+10;
int a[maxn];
int L[maxn],R[maxn],lazy[maxn],pos[maxn];//sum[maxn]
int n,m;
inline ll read(){//仅限于读取整数，实数还是老老实实打scanf 
	ll x=0,f=1;
	char ch; ch=getchar();
	while(ch<'0' || ch>'9') {//过滤非数字字符 
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f; 
}
inline void update(int l,int r,int c){
	int p=pos[l],q=pos[r];
	if(p==q){//在一个块内，暴力处理 
		for(int i=l;i<=r;i++) a[i]+=c; 
	} else {
		//不在一个块内，分三部分，完整的块和两个非完整的块
		for(int i=p+1;i<=q-1;i++) lazy[i]+=c;//完整块，统一处理
		for(int i=l;i<=R[p];i++) a[i]+=c;//前部分非完整块
		for(int i=L[q];i<=r;i++) a[i]+=c;//后部分非完整块 
	}
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int t=sqrt(n);
	for(int i=1;i<=t;i++){//序列分成根号N块 
		L[i]=(i-1)*t+1; R[i]=i*t; 
	}
	if(R[t]<n) t++,L[t]=R[t-1]+1,R[t]=n;//处理后面的小部分 
	for(int i=1;i<=t;i++){//把位置映射到块上，O(n) 
		for(int j=L[i];j<=R[i];j++) pos[j]=i;
	} 
	for(int i=1;i<=m;i++){
		int opt,l,r,c;
		opt=read();
		if(opt==0){//修改操作 
			l=read();r=read();c=read();
			update(l,r,c);//修改操作
		}
		if(opt==1){//查询操作 
			l=read();
			int q=pos[l];
			printf("%d\n",a[l]+lazy[q]);
		}
	}
	return 0;
} 
