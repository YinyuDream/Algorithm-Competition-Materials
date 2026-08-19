#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+10;
int n,q,cnt;
int prime[maxn],not_prime[maxn];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		if(!not_prime[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			not_prime[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1,x;i<=q;i++){
		scanf("%d",&x);
		printf("%d\n",prime[x]);
	}
	return 0;
}
