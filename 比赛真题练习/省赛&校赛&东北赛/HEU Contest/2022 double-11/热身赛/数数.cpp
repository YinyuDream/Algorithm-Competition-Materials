#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans+=i+j;
	printf("%d",ans);
	return 0;
}