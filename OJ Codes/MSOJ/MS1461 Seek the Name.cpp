#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=4e5+10;
char a[maxn];
int nextn[maxn],ans[maxn],top;
void solve()
{
	memset(nextn,0,sizeof nextn),top=0;
	int l=strlen(a),j=0;
	for(int i=1;i<l;i++)
	{
		while(a[i]!=a[j]&&j)
			j=nextn[j-1];
		j+=(a[i]==a[j]);
		nextn[i]=j;
	}
	while(j){
		ans[++top]=j;
		j=nextn[j-1];
	}
	for(int i=top;i>=1;i--)
		printf("%d ",ans[i]);
	printf("%d",l);
	puts(""); 
}
int main(){
	while(scanf("%s",a)!=EOF)solve();
	return 0;
} 
