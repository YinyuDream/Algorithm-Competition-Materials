// LUOGU_RID: 90799946
#include<bits/stdc++.h>
const int maxn=1e6+10;
int n,top,cnt,a[maxn],pos[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]%=2;
	for(int i=1;i<n;i++)
		if(!a[i]&&!a[i+1])
			a[i]=a[i+1]=1;
	for(int i=1;i<=n;i++)
		if(!a[i])
			pos[++top]=i;
	pos[++top]=n+1;
	for(int i=0;i<top;i++)
		if((pos[i+1]-pos[i]-1)%2)
			cnt++;
	if(cnt)puts("NO");
	else puts("Yes");
}