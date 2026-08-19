#include<cstdio>
using namespace std;
int t=50,k;
int main(){
	for(int i=1;i<=7;i++)
		scanf("%d",&k),t+=k;
	scanf("%d",&k);
	if(k)t+=5;
	scanf("%d",&k); 
	if(t<k)puts("AFO");
	else puts("AKIOI");
	return 0;
}