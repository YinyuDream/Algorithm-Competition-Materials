#include<string>
#include<iostream>
#include<map>
#include<ctime>
#include<cstdlib>
using namespace std;
const int mod=1e7+10,p=131,maxn=1e4+10;
int n,ans;
string s[maxn];
map<string,int>a;
int book[mod];
void Hash(string t,int k)
{
	int sum=0;
	for(auto it=t.begin();it!=t.end();it++)sum=(sum*p+(*it))%mod;	 
	while(book[sum]&&s[book[sum]]!=s[k])sum++;
	if(book[sum]==0)ans++,book[sum]=k;
}
void solve1()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		a[s[i]]++;
	}
	cout<<a.size()<<endl;
}
void solve2()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		Hash(s[i],i);
	}
	cout<<ans<<endl;
}
int main(){
	srand(time(0));
	rand()%2?solve2():solve1();
	return 0;
} 