#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int n,m;
char a[maxn],b[maxn],c[maxn],pas[maxn],rev[maxn];
int main(){
	scanf("%s%s%s",a+1,b+1,c+1);
	n=strlen(a+1),m=strlen(c+1);
	for(int i=1;i<=n;i++)
	{
		if(!pas[b[i]])pas[b[i]]=a[i];
		else if(pas[b[i]]==a[i])continue;
		else{
			puts("Failed");
			return 0;
		}
	}
	for(int i='A';i<='Z';i++)
		if(!pas[i])
		{
			puts("Failed");
			return 0;
		}
	for(int i='A';i<='Z';i++)
		rev[pas[i]]=i;
	for(int i=1;i<=m;i++)
		c[i]=rev[c[i]];
	printf("%s",c+1);
	return 0;
}