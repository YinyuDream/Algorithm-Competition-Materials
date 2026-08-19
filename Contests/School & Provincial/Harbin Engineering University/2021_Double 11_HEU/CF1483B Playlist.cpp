#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,top,cnt;
int a[maxn],pre[maxn],net[maxn],ans[maxn],net1[maxn],_pos[maxn];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int first_iterator()
{
	memset(_pos,0,sizeof _pos);
	int tot=0;
	for(int i=1;i<=n;i=net[i]){
		if(gcd(a[i],a[net[i]])==1&&net[i]>i){
			_pos[++tot]=i;
			i=net[i];
			if(i==n)break;
		}
		if(net[i]<=i)break;
	}
	if(_pos[tot]!=n-1&&gcd(a[n],a[1])==1)
		_pos[++tot]=n;
	for(int i=1;i<tot;i++)
		net[_pos[i]]=_pos[i+1];
	for(int i=2;i<=tot;i++)
		pre[_pos[i]]=_pos[i-1];
	for(int i=1;i<=tot;i++)
		net1[_pos[i]]=(_pos[i]+1)<=n?_pos[i]+1:_pos[i]+1-n;
	net[_pos[tot]]=_pos[1];
	pre[_pos[1]]=_pos[tot];
	//for(int i=1;i<=n;i++)
	//	printf("ss%d %d %d\n",_pos[i],net[_pos[i]],net1[_pos[i]]);
	return _pos[1];
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		top=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
			net[i]=i+1;
		for(int i=2;i<=n;i++)
			pre[i]=i-1;
		pre[1]=n,net[n]=1;
		int pos=first_iterator();
		cnt=0;
		while(1)
		{
			sleep(1);
			//for(int i=1;i<=n;i++)
			//	printf("ss%d %d %d %d\n",i,pre[i],net[i],net1[i]);
			//printf("%d\n",pos);
			//puts("");
			printf("%d %d\n",pos,net1[pos]);
			if(gcd(a[pos],a[net1[pos]])==1)
				ans[++top]=net1[pos],cnt++;
			net1[pos]++;
			if(net1[pos]>n)net1[pos]-=n;
			if(gcd(a[net1[pos]],a[pos])==1){
				//sleep(1);
				if(net1[pos]>n)net1[pos]-=n;
				if(net1[pos]==net[pos]){
					net[pos]=net[net[pos]];
					pre[net[pos]]=pos;
				}
			}else{
				net[pre[pos]]=net[pos];
				pre[net[pos]]=pre[pos];
			}
			if(net[pos]<=pos){
				//printf("%d",cnt);
				if(!cnt)break;
				cnt=0;
			}
			pos=net[pos];
		}
		/*printf("ss%d ",top);
		for(int i=1;i<=top;i++)
			printf("ss%d ",ans[i]);
		puts("");*/
	}
	return 0;
}