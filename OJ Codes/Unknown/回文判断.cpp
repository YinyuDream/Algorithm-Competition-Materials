#include<cstdio>
#include<cstring>
using namespace std;
int t; 
char a[10000];
char b[10000];
int main()
{
	scanf("%s",a);
	t=strlen(a);
	for(int i=0;i<=t;i++)b[i]=a[t-i-1];
	t=strcmp(a,b);
	if(t==0)printf("Yes");
	else printf("No");
	return 0;
}
