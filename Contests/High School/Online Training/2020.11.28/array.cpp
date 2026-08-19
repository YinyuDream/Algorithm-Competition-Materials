#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int T,m;
ll max_b,k,d,a[maxn],b[maxn];
bool cmp(ll a,ll b){
	return a>b;
}
ll solve()
{
	memset(b,0,sizeof b);
	ll limit=d,num=0,ans=0;
	for(int i=1;i<=m;i++){
		if(limit-max_b*a[i]>0){
			limit-=max_b*a[i];
			b[i]=max_b;
		}else{
			b[i]=limit/a[i];
			limit=0;
			break;
		}
	}
	for(int i=1;i<=m;i++)
		num+=b[i];
	num+=k*b[m],ans=num,limit=d-limit;
	int l=lower_bound(b+1,b+m+1,b[m],cmp)-b-1,r=l+1;
	while(l>=1){
		if(r==m+1)r=lower_bound(b+1,b+m+1,b[m],cmp)-b;
		if((limit-a[l]+a[r]<=d&&b[l]-1<b[r]+1)||(limit-a[l]+a[r]>d&&b[l]-1<b[r]))r++,l--;
		if(r==m+1)r=lower_bound(b+1,b+m+1,b[m],cmp)-b;
		if(limit-a[l]+a[r]<=d){
			b[l]--,b[r]++,limit+=a[r]-a[l];
			if(r==m)num+=k;
			r++;
		}else{
			b[l]--,limit-=a[l],num--;
		}
		ans=max(ans,num);
	}
	return ans;
}
int main(){
	//freopen("array.in","r",stdin);
	//freopen("array.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%d%lld%lld",&max_b,&m,&k,&d);
		for(int i=1;i<=m;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+m+1);
		printf("%lld\n",solve());
	}
	return 0;
}
