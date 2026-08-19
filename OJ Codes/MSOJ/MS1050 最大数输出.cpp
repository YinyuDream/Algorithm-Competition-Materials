#include<cstdio>
int a,b,c,d,e;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a<b){
		e=b;
	}else{
		e=a;
	}
	
	if(e<c){
		d=c;
	}else{
		d=e;
	}
	printf("%d",d);
	return 0;
}
