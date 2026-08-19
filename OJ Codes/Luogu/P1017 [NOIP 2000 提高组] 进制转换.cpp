#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100;
int n,top,base,ans[maxn];
char a[maxn];
void change(int x)
{
	while(x){
		
		ans[++top]=x%base;
		x/=base;
	}
	for(int i=1;i<=top;i++)
	a[i]=ans[i]>=10?ans[i]-10+'A':ans[i]+'0';
	reverse(a+1,a+top+1);
}
int main(){
	scanf("%d%d",&n,&base);
	change(n);
	printf("%d=%s(base%d)",n,a+1,base);
}
