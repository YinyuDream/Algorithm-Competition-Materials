#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn];
bool check(int dis)
{
	int t1=a[1]+2*dis,t2=0,t3=0;
	if(t1>=a[n])return true;
	for(int i=1;i<=n;i++)
		if(t1<a[i]){
			t2=a[i];
			break;
		}
	t2+=2*dis;
	if(t2>=a[n])return true;
	for(int i=1;i<=n;i++)
		if(t2<a[i]){
			t3=a[i];
			break;
		}
	t3+=2*dis;
	if(t3>=a[n])return true;
	else return false;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		int l=0,r=1e9;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}