#include<bits/stdc++.h>
using namespace std;
int T;
long long n,x,y;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>x>>y;
        long long lcm=x*y/gcd(x,y);
        long long cnt_x=n/x,cnt_y=n/y,cnt_lcm=n/lcm;
        long long cnt_up=cnt_x-cnt_lcm,cnt_down=cnt_y-cnt_lcm;
        cout<<-(cnt_down+1)*cnt_down/2+(n+n-cnt_up+1)*cnt_up/2<<endl;
	}
	return 0;
}