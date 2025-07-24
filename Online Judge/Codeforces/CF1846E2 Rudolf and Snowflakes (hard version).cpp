#include<bits/stdc++.h>
using namespace std;
int T;
__int128 m;
__int128 read()
{
	__int128 x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
__int128 power(__int128 x,__int128 p)
{
	__int128 ans=1;
	for(int i=1;i<=p;i++)
		ans*=x;
	return ans;
}
int main(){
	T=read();
	while(T--){
		m=read();
		for(__int128 n=3;n<=60;n++){
			__int128 l=2,r=pow(m,1.0/(n-1));
			while(l<=r){
				__int128 mid=(l+r)/2;
				__int128 ans=(power(mid,n)-1)/(mid-1);
				if(ans<m)l=mid+1;
				else if(ans==m){
					cout<<"YES"<<endl;
                    goto flag;
				}
				else r=mid-1;
			}
		}
	    cout<<"NO"<<endl;
        flag:;
	}
	return 0;
}