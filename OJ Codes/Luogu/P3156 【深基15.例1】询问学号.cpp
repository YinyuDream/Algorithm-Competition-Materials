#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,m;
int a[maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1,q;i<=m;i++)
		cin>>q,cout<<a[q]<<endl;
}