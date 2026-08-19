#include<cstdio>
#include<algorithm>
using namespace std;
const int N=12;
int n,ans;
struct node{
	char a[N][N];
	void rev1(){
		char b[N][N]={0};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				b[i][j]=a[n-j+1][i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			a[i][j]=b[i][j];
	}
	void rev2(){
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<=n;j++)
			 swap(a[j][i],a[j][n-i+1]); 
	}
	friend bool operator==(node a,node b){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a.a[i][j]!=b.a[i][j])return false;
			}
		}
		return true;
	}
}s,e,t;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf(" %c",&s.a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf(" %c",&e.a[i][j]);
	t=s; 
	for(int i=1;i<=3;i++){
		t.rev1();
		if(t==e){
			printf("%d",i);
			return 0;	
		}
	}
	t=s,t.rev2();
	if(t==e){
		printf("4");
		return 0;
	}
	t=s,t.rev2();
	for(int i=1;i<=3;i++){
		t.rev1();
		if(t==e){
			printf("5");
			return 0;
		}
	}
	if(s==e){
		printf("6");
		return 0;
	}
	printf("7");
	return 0;
} 
