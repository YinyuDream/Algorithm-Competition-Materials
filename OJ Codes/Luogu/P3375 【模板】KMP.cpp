#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
char a[maxn],b[maxn];
int nextn[maxn],l1,l2;
void getnext()
{
	int j=0;
	for(int i=1;i<l2;i++){
		while(b[i]!=b[j]&&j)
			j=nextn[j-1];
		j+=(b[i]==b[j]);
		nextn[i]=j;
	}
}
void kmp()
{
	int j=0;
	for(int i=0;i<l1;i++){
		while(a[i]!=b[j]&&j)
			j=nextn[j-1];
		j+=(a[i]==b[j]);
		if(j==l2)
			printf("%d\n",i-l2+2);
	}
	for(int i=0;i<l2;i++)
		printf("%d ",nextn[i]);
}
int main(){
	scanf("%s\n%s",a,b);
	l1=strlen(a),l2=strlen(b);
	getnext();
	kmp(); 
	return 0;
} 