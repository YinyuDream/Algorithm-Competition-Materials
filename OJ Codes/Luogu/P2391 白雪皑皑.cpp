#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,p,q;
int a[maxn],fa[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1;i<=n+1;i++)
		fa[i]=i;
	for(int i=m,l,r;i>=1;i--){
		l=(i*p+q)%n+1,r=(i*q+p)%n+1;
		if(l>r)swap(l,r);
		for(int j=l;j<=r;){
			int t=find(j);
			if(t==j){
				a[j]=i;
				fa[j]=find(j+1);
			}
			j=fa[j];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]);
	return 0;
}