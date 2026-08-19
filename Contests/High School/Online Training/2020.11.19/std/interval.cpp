#include<bits/stdc++.h>
#define N 500050
using namespace std;

int a[N],n,ans,p[N],c,R[N],L[N],C,v[N];

int main(){
	freopen("data.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,r=1;i<=n;i=r){
		while(r<=n&&a[r]%a[i]==0)r++;
		for(int j=r;j>=i;j--)R[j]=r;
	}
	for(int i=n,l=n;i;i=l){
		while(l&&a[l]%a[i]==0)l--;
		for(int j=i;j>=l;j--)L[j]=l;
	}
	for(int i=1;i<=n;i++)
		if(R[i]-L[i]-2>ans)ans=R[i]-L[i]-2,c=1,p[0]=L[i]+1,v[L[i]]=++C;
		else if(R[i]-L[i]-2==ans&&v[L[i]]!=C)p[c++]=L[i]+1,v[L[i]+1]=C;
	printf("%d %d\n",c,ans);
	for(int i=0;i<c;i++)
		printf("%d ",p[i]);
	return 0;
}

