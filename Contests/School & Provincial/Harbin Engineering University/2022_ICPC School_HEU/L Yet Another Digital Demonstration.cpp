#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,tot,n;
int num[10],mul[maxn][10];
void work(int x){
	int t=1;
	while(t<=9){
		num[t]=x%10;
		x/=10;
		t++;
	}
}
void pre_work(){
	for(int i=0;i<=999999999;i+=114514){
		tot++;
		int t=1,x=i;
		while(t<=9){
			mul[tot][t]=x%10;
			x/=10;
			t++;
		}
	}
}
int solve(int x){
	int mx=0x7f7f7f7f;
	for(int i=1,sum;i<=tot;i++){
		sum=0;
		for(int j=1;j<=9;j++){
			if(num[j]!=mul[i][j])
				sum++;
		}
		mx=min(mx,sum);
	}
	return mx;
}
int main(){
	pre_work();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		work(n);
		printf("%d\n",solve(n));			
	}
	return 0;
}