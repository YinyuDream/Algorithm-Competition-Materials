#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int book[maxn],ans[maxn],top;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(book,0,sizeof book);
		scanf("%d",&n);
		puts("2");
		top=0;
		for(int i=1;i<=n;i++){
			if(!book[i]){
				for(int j=1;j*i<=n;j=(j<<1)){
					book[j*i]=1;
					ans[++top]=j*i;
				}
			}
		}
		for(int i=1;i<=top;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}