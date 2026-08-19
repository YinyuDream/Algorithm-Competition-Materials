#include<cstdio>
using namespace std;
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if((a>60&&b>60)||(a<60&&b<60)){
		printf("0");
	}else{
		printf("1");
	}
	return 0;
}