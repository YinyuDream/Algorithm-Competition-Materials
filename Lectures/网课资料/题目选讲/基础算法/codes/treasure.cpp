#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
template <typename T>
inline void _read(T& x){
	char ch=getchar();bool sign=true;
	while(!isdigit(ch)){if(ch=='-')sign=false;ch=getchar();}
	for(x=0;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	if(!sign)x=-x;
}
int n,k,K;
int t[55],a[55],b[55],c[55];
int id[55][55];
int cnt[55];
int Type[55];

ll ans=0;//记得用long long 否则拿不到100分 

/*void dfs(int num,int A,int B,int C){
	//当前讨论第num个非空类选择哪一个物品（因为选一个一定比不选优） 
	if(num>K){
		ans=max(ans, 1LL*A*B*C);
		return;
	}
	int type=Type[num];//第num个非空类为Type[num] 
	for(int i=1;i<=cnt[type];i++){//依次尝试每一个物品 
		int v=id[type][i];
		dfs(num+1,A+a[v],B+b[v],C+c[v]);
	}
}*/
void dfs(int num,int A,int B,int C){
	//当前讨论第num个类选择哪一个物品（因为选一个一定比不选优） 
	if(num>K){
		ans=max(ans, 1LL*A*B*C);
		return;
	}
	if(cnt[num]==0)dfs(num+1,A,B,C);
	int type=num;//Type[num];//第num个非空类为Type[num] 
	for(int i=1;i<=cnt[type];i++){//依次尝试每一个物品 
		int v=id[type][i];
		dfs(num+1,A+a[v],B+b[v],C+c[v]);
	}
} 
int main(){
	int i,j,type;
	cin>>n>>k;
	
	for(i=1;i<=n;i++){
		_read(type);_read(a[i]);_read(b[i]);_read(c[i]);
		cnt[type]++;  //type类的物品数+1 
		id[type][cnt[type]]=i;  //type类的第cnt[type]个物品编号为i 
	}
	
	//统计所有非空类，K表示非空种类数量，非空的种类存入Type数组 
	for(i=1;i<=k;i++){
		if(cnt[i]==0)continue;
		K++;
		Type[K]=i;
	}
	
	dfs(1,99,99,99);
	
	printf("%lld\n",ans);
}

