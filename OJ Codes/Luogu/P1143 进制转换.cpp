#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=50;
int n,m,top,num[maxn],pow[maxn],ans[maxn];
char s[maxn];
int n_to_ten(int l)
{
	int ans=0;
	pow[0]=1;
	for(int i=1;i<=l;i++)
		pow[i]=pow[i-1]*n;
	for(int i=l;i>=1;i--)
		ans+=pow[l-i]*num[i];
	return ans;
}
void ten_to_m(int x)
{
	while(x){
		ans[++top]=x%m;
		x/=m;
	}
}
int main(){
	scanf("%d\n%s\n%d",&n,s+1,&m);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++)
		num[i]=(s[i]>='0'&&s[i]<='9')?(s[i]-'0'):(s[i]-'A'+10);
	int t=n_to_ten(l);
	ten_to_m(t);
	if(m<=10){
		for(int i=top;i>=1;i--)
		printf("%d",ans[i]);
	}else{
		for(int i=top;i>=1;i--)
		printf("%c",ans[i]<10?'0'+ans[i]:'A'+ans[i]-10);
	}
	return 0;
}
