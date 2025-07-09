#include<cstdio>
#include<cmath>
using namespace std;
int n;
double ans=1;
int main(){
	freopen("data.in","r",stdin);
	scanf("%d",&n);
	if(n<=20000000){
			for(int i=1;i<n;i++)
				ans+=1.0/i;
	}else{
		for(int i=1;i<=20000000;i++){
			ans+=1.0/i;
		}
		int t=20000001;
		while(t+10<n)
			ans+=10.0/t,t+=10;
	}
	printf("%.6f",ans);
	return 0;
}