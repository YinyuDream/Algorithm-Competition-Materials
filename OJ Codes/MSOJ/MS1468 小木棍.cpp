#include<cstdio>
using namespace std;
const int maxn=70;
int k,n;
int a[maxn];
int main(){
	scanf("%d",&k);
	for(int i=1,p;i<=k;i++)
	{
		scanf("%d",&p);
		if(p<=50)a[++n]=p; 
	}
	return 0;
} 
