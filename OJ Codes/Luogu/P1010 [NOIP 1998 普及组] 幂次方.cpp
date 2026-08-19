#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n;
int k,a[maxn][maxn];
void output(int x)
{
	if(x==2){
		printf("2");
		return ;
	}
	if(x==1){
		printf("2(0)");
		return ;
	}
	int pow=0,pos=++k;
	while(x){
		a[pos][++pow]=x%2;
		x/=2;
	}
	int mn1=0;
	for(int i=1;i<=pow;i++)
		if(a[pos][i]){
			mn1=i;
			break;
		}	
	for(int i=pow;i;i--){
		if(a[pos][i]){
			if(i-1==1)
				printf("2");
			else if(i-1==0)
				printf("2(0)");
			else 
				printf("%d(",2),
				output(i-1),
				printf(")");
			if(i!=mn1)printf("+");
		}
	}
}
int main(){
	scanf("%d",&n);
	output(n);
	return 0;
}