#include<cstdio>
int x,y;
int main(){
	scanf("%d%d",&x,&y);
	if(x%y==0){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}