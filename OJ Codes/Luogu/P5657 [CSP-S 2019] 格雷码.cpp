#include<iostream>
const int maxn=64;
typedef unsigned long long Ull;
using namespace std;
bool ans[maxn];
int top=maxn;
int n;
Ull k;
void dfs(int x,Ull k){
	if(x==1){
		if(k==1)ans[--top]=0;
			else ans[--top]=1;
			return ;
	}
	Ull mid=1ull<<x-1;
	if(k<=mid)dfs(x-1,k),ans[--top]=0;
	else dfs(x-1,(1ull<<x)-k+1),ans[--top]=1;
}
int main(){
	cin>>n>>k;
	if(k==(1ull<<64)-1){
		for(int i=1;i<=64;i++)
			cout<<(i==1?1:0);
		return 0;
	}
	dfs(n,k+1);
	for(int i=top;i<=maxn-1;i++)
	cout<<ans[i];
	return 0;
}
