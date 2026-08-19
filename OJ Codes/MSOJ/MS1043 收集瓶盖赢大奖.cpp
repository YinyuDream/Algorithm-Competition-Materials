#include<cstdio>
using namespace std;
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(a>9||b>19){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}