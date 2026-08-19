#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n;
long long sum;
char a[maxn];
int num[maxn],nextn[maxn];
void kmp()
{
	int j=0;
	for(int i=1;i<n;i++){
		while(a[i]!=a[j]&&j)j=nextn[j-1];
		j+=(a[i]==a[j]);
		nextn[i]=j;
		if(nextn[i]==0)num[i]=0;
		else if(num[nextn[i]-1]!=0)num[i]=num[nextn[i]-1];
		else if(num[nextn[i]-1]==0)num[i]=nextn[i];
	}
}
int main(){
	scanf("%d\n%s",&n,a);
	kmp();
	for(int i=0;i<n;i++){
		sum+=num[i]?i+1-num[i]:0;
	}
	printf("%lld",sum);
	return 0;
}