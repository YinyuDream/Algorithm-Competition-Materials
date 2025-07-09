#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,x,y;
int delta[maxn];
int find(int val)
{
	for(int i=1;i<=n;i++)
		if(val==delta[i])
			return i;
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n;i++)	
			scanf("%d",&delta[i]);
		sort(delta+1,delta+n+1);
		int pos=find(abs(y-x));
		if(!pos){
			puts("ZERO");
			continue;
		}
		if(y<x){//mid value<x  ...... -2
			if(n-pos<n/2)puts("ZERO");
			else puts("El Psy Congroo!");
		}else if(y>x){//....... 2 .......
			if(n-pos<n/2)puts("ZERO");
			else puts("El Psy Congroo!");
		}else puts("El Psy Congroo!");
	}
	return 0;
}