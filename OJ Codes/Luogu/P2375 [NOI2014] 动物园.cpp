#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10,p=1e9+7;
int n;
char a[maxn];
int nextn[maxn],num[maxn];
void kmp(){
	int j=0,l=strlen(a);
	memset(nextn,0,sizeof nextn);
	num[0]=1;
	for(int i=1;i<l;i++){
		while(a[i]!=a[j]&&j)j=nextn[j-1];
		j+=(a[i]==a[j]);
		nextn[i]=j;num[i]=num[j-1]+1;
	}
}
long long getnum()
{
	int j=0,l=strlen(a);
	long long ans=1;
	for(int i=1;i<l;i++){
		while(a[i]!=a[j]&&j)j=nextn[j-1];
		j+=(a[i]==a[j]);
		if(j*2>i+1)j=nextn[j-1];
		ans=(ans*(num[j-1]+1))%p;
	}
	return ans;
}
int main(){
	//freopen("P2375_1.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("\n%s",a);
		kmp();
		printf("%lld\n",getnum());
	}
	return 0;
}