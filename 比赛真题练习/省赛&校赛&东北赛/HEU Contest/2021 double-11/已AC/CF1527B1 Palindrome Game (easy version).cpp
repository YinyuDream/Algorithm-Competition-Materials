#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int T,n,tot;
int a[maxn];
char s[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		tot=0;
		scanf("%d\n%s",&n,s+1);
		for(int i=1;i<=n;i++){
			a[i]=s[i]-'0';
			if(!a[i])tot++;
		}
		if(n%2==0||tot==1){
			puts("BOB");
		}else{
			if(a[n/2+1])puts("BOB");
			else puts("ALICE");
		}
	}
	return 0;
}