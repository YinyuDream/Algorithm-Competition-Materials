#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,sum;
int a[maxn],b[maxn],c[maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;i++)
		sum+=a[i]*b[i]*c[i];
	cout<<sum/m+(sum%m!=0)<<" "<<m*(sum%m==0)+sum%m;
	return 0;
}