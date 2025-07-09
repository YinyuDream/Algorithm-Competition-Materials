#include<bits/stdc++.h>
using namespace std;
const int N=19,maxn=3e5;
int n,mx,a[maxn];
struct fenshu{
	int fz,fm;
	fenshu(){
		fz=fm=1;
	}
};
fenshu p[N][maxn];
fenshu operator/(fenshu a,int b){
	fenshu c=a;
	c.fm*=2;
	return c; 
}
fenshu operator=(fenshu a,int b){
	fenshu c=a;
	c.fz=b,c.fm=1;
}
fenshu p[N][maxn];
int pow[N];
int main(){
	pow[0]=1;
	for(int i=1;i<N;i++)
		pow[i]=pow[i-1]*2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mx=max(mx,a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]<mx)
			a[i]=0;
	for()
	return 0;
}