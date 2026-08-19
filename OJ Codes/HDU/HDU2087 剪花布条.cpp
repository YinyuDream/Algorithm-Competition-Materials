#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
char a[maxn],b[maxn];
int nextn[maxn],l1,l2;
void getnext()
{
	memset(nextn,0,sizeof nextn);
	int j=0;
	for(int i=1;i<l2;i++)
	{
		while(b[j]!=b[i]&&j)j=nextn[j-1];
		j+=(b[i]==b[j]);
		nextn[i]=j;
	}
}
int kmp()
{
	int j=0,cnt=0,maxp=-1;
	for(int i=0;i<l1;i++)
	{
		while(a[i]!=b[j]&&j)j=nextn[j-1];
		j+=(a[i]==b[j]);
		if(j==l2){
			if(i-l2+1>maxp)cnt++,maxp=i;
		}
	}
	return cnt;
}
int main(){
	while(1){
		scanf("%s",a),l1=strlen(a);
		if(a[0]=='#')break;
		scanf("%s",b),l2=strlen(b);
		getnext();
		printf("%d\n",kmp());
	}
	return 0;
} 