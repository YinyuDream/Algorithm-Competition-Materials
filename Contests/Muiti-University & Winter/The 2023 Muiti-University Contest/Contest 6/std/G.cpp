#include <bits/stdc++.h>
using namespace std;
//����ocd(x,y)=gcd(|x|,|y|) 
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	// freopen("3.in","r",stdin);
	// freopen("3.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if (z==0)
		{
			if (x!=0&&y!=0) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
			continue;
		}
		if (z%gcd(x,y)==0)
		{
			cout<<"YES"<<endl;
		}else cout<<"NO"<<endl; 
	}
	return 0;
}
/*
3
2 4 2
2 4 1
5 6 1
*/