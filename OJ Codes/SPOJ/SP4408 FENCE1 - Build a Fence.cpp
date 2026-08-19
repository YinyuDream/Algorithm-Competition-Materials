#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1);
int n;
int main(){
	while(scanf("%d",&n)&&n)
	printf("%.2f\n",pi*(n/pi)*(n/pi)/2);
}
