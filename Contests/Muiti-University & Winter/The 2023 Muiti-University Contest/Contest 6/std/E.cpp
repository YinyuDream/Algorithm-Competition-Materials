#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[N],sum[N],sum2[N];
int main()
{
	// freopen("2.in","r",stdin);
	// freopen("2.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n,q;
		cin>>n>>q;
		for (int i=1;i<=n;i++) cin>>a[i],sum[i]=(sum[i-1]+a[i])%2;
		for (int i=1;i<=n;i++)
		  sum2[i]=sum2[i-1]+(sum[i]^1)%2;
		for (int i=1;i<=q;i++)
		{
			int x,y,k,t;
			cin>>x>>y>>k;
			if (sum[x-1]==0) t=sum2[y]-sum2[x-1];
			else t=(y-x+1)-(sum2[y]-sum2[x-1]);
			if (t>=k&&(sum[y]-sum[x-1])%2==0) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
/*
2
3 3
1 2 3
1 2 1
1 3 1
2 3 1
3 3
2 2 2 
1 2 1
1 2 2
1 2 3
*/
