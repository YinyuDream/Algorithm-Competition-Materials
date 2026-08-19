#include<cstdio>
using namespace std;
int a,b,sum;
int main(){
	scanf("%d%d",&a,&b);
	if(a>b){
		int t;
		t=a;
		a=b;
		b=t;
	}
	for(int i=a;i<=b;i++){
		if(i%17==0)sum=sum+i;
	}
	printf("%d",sum);
	return 0;
}