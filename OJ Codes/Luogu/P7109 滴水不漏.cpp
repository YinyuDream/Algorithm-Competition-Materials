#include<cstdio>
using namespace std;
int n,a,b;
int main(){
	scanf("%d",&n);
	printf("? %d %d\n",1,1);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	if(t==0)a=0;
	else a=1;
	if(a==1){
		printf("? %d %d\n",1,2);
		fflush(stdout);
		int c;
		scanf("%d",&c);
		if(c==1){
			printf("? %d %d\n",1,1);
			fflush(stdout);
			int q;
			scanf("%d",&q);
			if(q==1)b=2;
			else b=1;
		}else b=0;
	}else{
		printf("? %d %d\n",2,2);
		fflush(stdout);
		int c;
		scanf("%d",&c);
		if(c==1){
			b=2;
		}else{
			printf("? %d %d\n",2,1);
			fflush(stdout);
			int q;
			scanf("%d",&q);
			if(q==1)b=1;
			else b=0;
		}
	}
	printf("! %d %d\n",a,b);
	fflush(stdout);
	return 0;
}
