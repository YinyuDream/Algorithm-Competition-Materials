#include<cstdio>
using namespace std;
int n;
int f(int x){
	return x==1?x:x*f(x-1); 
}
int main(){
	scanf("%d",&n);
	printf("%d",f(n));
} 
