#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string dirs="RULD";
	long long n,xt,yt;
//	n=100,xt=5,yt=0;
	cin>>n>>xt>>yt;
	if(xt<0)swap(dirs[0],dirs[2]),xt*=-1;
	if(yt<0)swap(dirs[1],dirs[3]),yt*=-1;
	if(yt>xt)swap(dirs[0],dirs[1]),swap(dirs[2],dirs[3]),swap(xt,yt);
	const vector<int> dx={1,0,-1,0};
	const vector<int> dy={0,1,0,-1};
	set<pair<long long,long long>> vis;
	string sol;
	long long lx=0,ly=0;
//	int cntr=0;
//	int minnow=1e9;
	int END=0;
	function<void(int,long long,long long)> dfs=[&](int now,long long x,long long y)
	{
		if(END)return;
		if(x==xt and y==yt)
		{
			cout<<"YES"<<endl;
			cout<<sol<<endl;
			END=1;
			return;
		}
		
		if(now==0)return;
		if(vis.find({xt,yt})!=vis.end())return;
		if(abs(x-xt)+abs(y-yt)>(now+1)*now/2)return;
		for(int d=0;d<4;d++)
		{
			int good=1;
			for(int i=1;i<=now;i++)
			{
				if(vis.find({x+dx[d]*i,y+dy[d]*i})!=vis.end())
				{
					good=0;
					break;
				}
			}
			if(good and (x+dx[d]*now>lx or y+dy[d]*now>ly)) // ban 4th-quadrant
			{
				for(int i=1;i<=now;i++)
				{
					vis.insert({x+dx[d]*i,y+dy[d]*i});
				}
				sol+=dirs[d];
				dfs(now-1,x+dx[d]*now,y+dy[d]*now);
				if(END)return;
				sol.pop_back();
				for(int i=1;i<=now;i++)
				{
					vis.erase({x+dx[d]*i,y+dy[d]*i});
				}
			}
		}
	};
	long long maxv=n*(n+1)/2;
	if(xt+yt>maxv)
	{
		cout<<"NO"<<endl;
		return;
	}
	long long del=max((maxv-(xt+yt)-300000)/2,0ll);
	int now=n;
	long long ss=0,x=0,y=0;
	
	vis.emplace(0,0);
	//step 1
	if(del)
	{
		while(ss<del)
		{
			sol.push_back(dirs[2]);
			ss+=now;
			x-=now;
			now--;
		}
		sol.push_back(dirs[3]);
		y-=now;
		now--;
		while(x<0)
		{
			sol.push_back(dirs[0]);
			x+=now;
			now--;
		}
		for(int i=0;i<=x;i++)vis.emplace(i,y);
	}
	
	//step 2 (x,y)->(xt,yt)
	while(yt-y>100000)
	{
		sol.push_back(dirs[1]);
		y+=now;
		now--;
	}
	while(xt-x>100000)
	{
		sol.push_back(dirs[0]);
		x+=now;
		now--;
	}
	if(x<xt)lx=max(lx,x-1);
	ly=max(ly,y-1);
	
	if(sol.empty())lx=-1e10,ly=-1e10;
	
	//step 3
	dfs(now,x,y);
	
	if(not END)cout<<"NO"<<endl;
}
int main()
{
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		solve();
	}
	return 0;
}
