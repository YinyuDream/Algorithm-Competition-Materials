#include<cstdio>
#include<string>
#include<iostream>
#include<unordered_map>
const int maxn=1e6+10;
int n,m,p,cnt,ans=0x7f7f7f7f,tot,max_cnt,head,tail;
using namespace std;
unordered_map<string,int>mp,bk;
string a[maxn];
void pre_work()
{
	for(int i=1;i<=m;i++)
		if(mp[a[i]]&&!bk[a[i]])
			max_cnt++,bk[a[i]]++;
	bk.clear();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		mp[s]=1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		cin>>a[i];
	pre_work();
	if(max_cnt==0)return printf("0\n0"),0;
	while(tail<=m)
	{
		while(cnt<max_cnt&&tail<=m){
			if(!bk[a[tail]]&&mp[a[tail]])cnt++;
			bk[a[tail]]++;
			tail++;
		}
		while(cnt==max_cnt&&head<tail){
			ans=min(ans,tail-head);
			bk[a[head]]--;
			if(!bk[a[head]]&&mp[a[head]])cnt--;
			head++;
		}
	}
	printf("%d\n%d",max_cnt,ans);
}
