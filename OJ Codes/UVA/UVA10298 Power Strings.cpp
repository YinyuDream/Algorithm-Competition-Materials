#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int nextn[maxn];
char a[maxn];
int kmp()
{
	int j=0,l=strlen(a);
	for(int i=1;i<l;i++){
		while(a[i]!=a[j]&&j)j=nextn[j-1];
		j+=(a[i]==a[j]);
		nextn[i]=j;
	}
	return l%(l-nextn[l-1])?1:l/(l-nextn[l-1]);
}
int main(){
	while(1){
		scanf("%s",a);
		if(a[0]=='.')break;
		printf("%d\n",kmp());
	}
	return 0;
} 
