#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,d,h;
int a[maxn];
double ans;
double up_edge(int dy)
{
	return 1.0*d*(h-dy)/h;
}
int main(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>d>>h;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=2;i<=n;i++){
			int dy=a[i]-a[i-1];
			if(dy<h)ans+=(up_edge(dy)+d)*dy/2;
			else ans+=1.0*d*h/2;
		}
		ans+=1.0*d*h/2;
		printf("%.8f\n",ans);
	}
	return 0;
}