#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<bitset>
#include<stack>
#include<ctime>
#define dd double
#define ll long long
#define mp make_pair
#define pb push_back
#define N 1010
#define M 1010
using namespace std;
ll n,ans=1e18;
int main()
{
	cin>>n;
	for(ll i=0;i<5;i++)
	for(ll j=0;j<2;j++)
	for(ll k=0;k<2;k++)
	for(ll r=0;r<5;r++)
	for(ll c=0;c<2;c++)
	{
		ll s=2*i+5*j+10*k+20*r+50*c;
		ll rest=n-s;
		if(rest%100==0) ans=min(ans,i+j+k+r+c+rest/100);
	}
	cout<<ans<<endl;
}