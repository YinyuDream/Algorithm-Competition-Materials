#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m;
char a[maxn],b[maxn],nextn[maxn];
int main(){
	scanf("%s\n%s",a,b);
	n=strlen(a),m=strlen(b);
	for(int i=1,j=0;i<m;i++)
	{
		while(j&&a[i]!=a[j])
		j=nextn[j-1];
		j+=(a[i]=a[j]);
		nextn[i]=j;
	}
	for(int i=1,j=0;i<n;i++)
	{
		while(j&&a[i]!=b[j])
		j=nextn[j-1];
		j+=(a[i]==b[j]);
		
	}
	return 0;
}
