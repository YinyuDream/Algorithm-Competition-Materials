#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n;
char a[maxn];
unsigned long long hash_z[maxn],hash_rev[maxn],p[maxn];
bool check(int l1,int r1,int l2,int r2)
{
	return hash_z[r1]-hash_z[l1-1]*p[r1-l1+1]==hash_rev[r2]-hash_rev[l2+1]*p[r1-l1+1];
}
void Hash()
{
	memset(hash_z,0,sizeof hash_z);
	memset(hash_rev,0,sizeof hash_rev);
	for(int i=1;i<=n;i++)
	hash_z[i]=hash_z[i-1]*131+a[i]-'a';
	for(int i=n;i>=1;i--)
	hash_rev[i]=hash_rev[i+1]*131+a[i]-'a';
}
int divide_num(int pos)
{
	int l=0,r=min(pos-1,n-pos);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(pos-mid,pos-1,pos+mid,pos+1))
			l=mid+1;
		else 
			r=mid-1;
	 }
	 return r*2+1;
}
int divide_air(int pos)
{
	int l=0,r=min(pos,n-pos);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(pos-mid+1,pos,pos+mid,pos+1))
			l=mid+1;
		else
			r=mid-1;
	}
	return r*2;
}
int solve()
{
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,divide_num(i));
	for(int i=1;i<n;i++)
		ans=max(ans,divide_air(i));
	return ans;
}
int main(){
	p[0]=1;
	for(int i=1;i<maxn;i++)
		p[i]=p[i-1]*131;
	int k=0;
	while(++k){
		scanf("%s",a+1);
		n=strlen(a+1);
		if(a[1]=='E')break;
		Hash();
		printf("Case %d: %d\n",k,solve());
	}
	return 0;
}