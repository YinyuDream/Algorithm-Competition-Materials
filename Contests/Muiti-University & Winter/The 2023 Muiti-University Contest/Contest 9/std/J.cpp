#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<vector<int>> a(4*n+5,vector<int>(4*n+5));
	for(int i=1;i<=4*n;i++)
		for(int j=1;j<=4*n;j++)
			cin>>a[i][j];
	auto fill=[&](vector<vector<int>> &b,int x,int y)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				b[x+i*2][y+j*2]=1;
	};
	auto check=[&](vector<vector<int>> &b)
	{
		vector<int> cntr(4*n+5),cntc(4*n+5),cntb(4*n+5);
		for(int i=1;i<=4*n;i++)
			for(int j=1;j<=4*n;j++)
				if(b[i][j])
				{
					cntr[i]++;
					cntc[j]++;
					cntb[a[i][j]]++;
				}
		for(int i=1;i<=4*n;i++)
		{
			if(cntr[i]!=n)return false;
			if(cntc[i]!=n)return false;
			if(cntb[i]!=n)return false;
		}
		return true;
	};
	{
		vector<vector<int>> ans(4*n+5,vector<int>(4*n+5));
		fill(ans,1,2);
		fill(ans,2*n+1,1);
		fill(ans,2,2*n+2);
		fill(ans,2*n+2,2*n+1);
		if(check(ans))
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=4*n;i++)
				for(int j=1;j<=4*n;j++)
					if(ans[i][j])
						cout<<i<<' '<<j<<"\n";
			return 0;
		}
	}
	{
		vector<vector<int>> ans(4*n+5,vector<int>(4*n+5));
		fill(ans,2,1);
		fill(ans,2*n+2,2);
		fill(ans,1,2*n+1);
		fill(ans,2*n+1,2*n+2);
		if(check(ans))
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=4*n;i++)
				for(int j=1;j<=4*n;j++)
					if(ans[i][j])
						cout<<i<<' '<<j<<"\n";
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
