#include<bits/stdc++.h>
#define N 100050
using namespace std;

priority_queue<int> a[N];
int n,q,x,y,z,ans;
int main(){
	freopen("two.in","r",stdin);
	freopen("two.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x,&y),a[x].push(-y),ans++;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)a[x].push(-y),ans++;
		else for(int k=sqrt(y),i=max(x-k,1);i<min(x+k+1,N);i++)
			while(!a[i].empty()&&-a[i].top()+(x-i)*(x-i)<=y)
				a[i].pop(),ans--;
		printf("%d\n",ans);
	}
	return 0;
}
