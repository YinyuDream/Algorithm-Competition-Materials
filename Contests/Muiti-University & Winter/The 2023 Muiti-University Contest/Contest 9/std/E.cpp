#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		vector<tuple<int,int,int>> ans;
		while(n and m)
		{
			if(n>m)
			{
				ans.emplace_back(n-m,0,m);
				n-=m;
			}
			else if(n<m)
			{
				ans.emplace_back(0,m-n,n);
				m-=n;
			}
			else
			{
				ans.emplace_back(0,0,n);
				n=m=0;
			}
		}
		cout<<"YES\n"<<ans.size()<<"\n";
		for(auto [x,y,l]:ans)cout<<x<<' '<<y<<' '<<l<<"\n";
	}
	return 0;
}
