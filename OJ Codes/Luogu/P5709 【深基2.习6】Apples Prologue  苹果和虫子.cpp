#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int m,t,s;
int main(){
	scanf("%d%d%d",&m,&t,&s);
	if(t==0)printf("%d",m),exit(0);
	int cnt=ceil((double)s/t);
	printf("%d",(m-cnt)>0?(m-cnt):0);
	return 0;
} 
