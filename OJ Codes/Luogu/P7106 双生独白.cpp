#include<cstdio>
using namespace std;
int t=15,a[15];
char s[15];
int main(){
	scanf("%s",s);
	printf("%c",'#');
	for(int i=1;i<=6;i++){
		if(s[i]>='A'&&s[i]<='F')a[i]=s[i]-'A'+10;
		else a[i]=s[i]-'0';
		a[i]=t-a[i];
		printf("%c",a[i]<=9?a[i]+'0':a[i]-10+'A');
	}
	return 0;
}
