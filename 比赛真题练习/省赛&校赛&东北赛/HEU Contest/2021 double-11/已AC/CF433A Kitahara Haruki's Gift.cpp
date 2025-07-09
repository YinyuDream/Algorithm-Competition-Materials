#include<bits/stdc++.h>
using namespace std;
int n,a,b,sum,flag;
int main(){
	scanf("%d",&n);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		if(t==100)a++;
		else b++;
		sum+=t;
	}
	for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++)
			if((i*100+j*200)*2==sum)
				flag=1;
	if(flag)puts("YES");
	else puts("NO");
	return 0;
}