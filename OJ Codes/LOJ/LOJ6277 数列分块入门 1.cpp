#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
const int maxn=50010;
int n,t,a[maxn],L[maxn],R[maxn],lazy[maxn],pos[maxn];
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
		x=x*10+(ch-'0'),ch=getchar(); 
	return x*f;
}
void ycl(){
	t=sqrt(n);
	for(int i=1;i<=t;i++)L[i]=(i-1)*t+1,R[i]=i*t; 
	if(R[t]<n)t++,L[t]=R[t-1]+1,R[t]=n;
	for(int i=1;i<=t;i++)for(int j=L[i];j<=R[i];j++)pos[j]=i;	
}
void update(int l,int r,int c){
	if(pos[l]==pos[r])for(int i=l;i<=r;i++)a[i]+=c;
	else{
		for(int i=l;i<=R[pos[l]];i++)a[i]+=c;
		for(int i=L[pos[r]];i<=r;i++)a[i]+=c;
		for(int i=pos[l]+1;i<=pos[r]-1;i++)lazy[i]+=c;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ycl();
	for(int i=1;i<=n;i++){
		int opt,l,r,c;
		opt=read();l=read();r=read();c=read();
		switch(opt){
			case(0):update(l,r,c);break;
			case(1):printf("%d\n",a[r]+lazy[pos[r]]);break;
		}	
	} 
	return 0;
}
