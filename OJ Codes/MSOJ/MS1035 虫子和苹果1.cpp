//Æ»¹ûºÍ³æ×Ó 
#include<cstdio>
int n,x,y,z,a;
double k,s;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	k=(double)y/x;
	s=n-k;
	a=(int)s;
	printf("%d",a);
	return 0;
}
