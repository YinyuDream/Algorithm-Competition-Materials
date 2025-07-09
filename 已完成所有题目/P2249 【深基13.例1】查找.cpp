#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,x,l,r;i<=m;i++){
		scanf("%d",&x);
		l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]<x)l=mid+1;
			else r=mid-1;
		}
		printf("%d ",a[l]==x?l:-1);
	}
	return 0;
}