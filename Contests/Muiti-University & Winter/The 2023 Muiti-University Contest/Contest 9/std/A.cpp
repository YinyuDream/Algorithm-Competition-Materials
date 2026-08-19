#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<string> S(2*n+5);
	S[0].resize(2*m+5,'+');
	for(int i=1;i<=2*n-1;i++)
	{
		string s;
		cin>>s;
		S[i]='+'+s;
	}
	vector<long long> R(n+5),C(m+5);
	int prt=0;
	for(int i=1;i<=n;i++)cin>>R[i],prt^=(R[i]&1);
	for(int j=1;j<=m;j++)cin>>C[j],prt^=(C[j]&1);
	if(prt==1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	vector<vector<long long>> a(n+5,vector<long long>(m+5));
	vector<vector<int>> cnt(n+5,vector<int>(m+5)),wr(n+5,vector<int>(m+5)),wc(n+5,vector<int>(m+5));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(S[i*2-1][j*2-2]=='+')wr[i][j]=1;
			else wr[i][j]=-1;
			if(S[i*2-2][j*2-1]=='+')wc[i][j]=1;
			else wc[i][j]=-1;
			cnt[i][j]=(S[i*2-1][j*2-2]=='-')+(S[i*2-2][j*2-1]=='-');
		}
	}
	int si=0,sj=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if((cnt[1][1]+cnt[i][1]+cnt[1][j]+cnt[i][j])%2==1)
			{
				si=i;sj=j;
				break;
			}
		}
		if(si)break;
	}
	mt19937_64 rng(58);
	auto randint=[&](long long l,long long r){return rng()%(r-l+1)+l;};
	const long long lim=1e12;
	if(not si)
	{
		auto fillin=[&]()
		{
			vector<long long> sr(n+5),sc(m+5);
			set<long long> used;
			for(int i=n;i>1;i--)
			{
				for(int j=m;j>1;j--)
				{
					a[i][j]=randint(-lim,lim);
					while(used.find(a[i][j])!=used.end())a[i][j]=randint(-lim,lim);
					used.insert(a[i][j]);
					sr[i]+=a[i][j]*wr[i][j];
					sc[j]+=a[i][j]*wc[i][j];
				}
				a[i][1]=(R[i]-sr[i])*wr[i][1];
				if(used.find(a[i][1])!=used.end())return false;
				used.insert(a[i][1]);
				sr[i]+=a[i][1]*wr[i][1];
				sc[1]+=a[i][1]*wc[i][1];
			}
			for(int j=m;j>=1;j--)
			{
				a[1][j]=(C[j]-sc[j])*wc[1][j];
				if(used.find(a[1][j])!=used.end())return false;
				used.insert(a[1][j]);
				sr[1]+=a[1][j]*wr[1][j];
				sc[j]+=a[1][j]*wc[1][j];
			}
			if(sr[1]!=R[1])
			{
				cout<<"NO"<<endl;
				exit(0);
			}
			return true;
		};
		for(int tt=1;tt<=5;tt++)
		{
			if(fillin())
			{
				cout<<"YES"<<endl;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
					{
						cout<<a[i][j]<<' ';
					}
					cout<<endl;
				}
				
				return 0;
			}
		}
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		auto fillin=[&]()
		{
			vector<long long> sr(n+5),sc(m+5);
			set<long long> used;
			for(int i=n;i>1;i--)
			{
				for(int j=m;j>1;j--)
				{
					a[i][j]=randint(-lim,lim);
					while(used.find(a[i][j])!=used.end())a[i][j]=randint(-lim,lim);
					used.insert(a[i][j]);
					sr[i]+=a[i][j]*wr[i][j];
					sc[j]+=a[i][j]*wc[i][j];
				}
				a[i][1]=(R[i]-sr[i])*wr[i][1];
				if(used.find(a[i][1])!=used.end())return false;
				used.insert(a[i][1]);
				sr[i]+=a[i][1]*wr[i][1];
				sc[1]+=a[i][1]*wc[i][1];
			}
			for(int j=m;j>=1;j--)
			{
				a[1][j]=(C[j]-sc[j])*wc[1][j];
				if(used.find(a[1][j])!=used.end())return false;
				used.insert(a[1][j]);
				sr[1]+=a[1][j]*wr[1][j];
				sc[j]+=a[1][j]*wc[1][j];
			}
			if(sr[1]==R[1])return true;
			used.erase(a[1][1]);
			used.erase(a[1][sj]);
			used.erase(a[si][sj]);
			used.erase(a[si][1]);
			long long del=(R[1]-sr[1])/2,ty=1;
			a[1][1]+=del*ty;
			if(wc[1][1]==wc[si][1])ty*=-1;
			a[si][1]+=del*ty;
			if(wr[si][1]==wr[si][sj])ty*=-1;
			a[si][sj]+=del*ty;
			if(wc[1][sj]==wc[si][sj])ty*=-1;
			a[1][sj]+=del*ty;
			if(wr[1][1]==wr[1][sj])ty*=-1;
			assert(ty==-1);
			if(used.find(a[1][1])!=used.end())return false;
			if(used.find(a[1][sj])!=used.end())return false;
			if(used.find(a[si][sj])!=used.end())return false;
			if(used.find(a[si][1])!=used.end())return false;
			return true;
		};
		for(int tt=1;tt<=5;tt++)
		{
			if(fillin())
			{
				cout<<"YES"<<endl;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
					{
						cout<<a[i][j]<<' ';
					}
					cout<<endl;
				}
				
				return 0;
			}
		}
		cout<<"NO"<<endl;
		return 0;
	}
	
	return 0;
}
