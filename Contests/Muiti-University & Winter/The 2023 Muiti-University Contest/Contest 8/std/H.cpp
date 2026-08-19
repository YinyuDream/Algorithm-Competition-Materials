#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
int a[MAXN];
bool ban[MAXN];
vector<int> loc[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	vector<int> que;
	que.push_back(n+1);
	ll res=0;
	for(int i=n;i>=1;i--)
	{
		if(!loc[a[i]+1].empty())
		{
			ban[loc[a[i]+1].back()]=1;
			loc[a[i]+1].pop_back();
		}
		if(a[i]>1)
		{
			loc[a[i]].push_back(i);
			que.push_back(i);
		}
		while(ban[que.back()])que.pop_back();
		res+=que.back()-i;
	}
	return 0*printf("%lld\n",res);
}