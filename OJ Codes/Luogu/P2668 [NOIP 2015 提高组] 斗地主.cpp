#include<bits/stdc++.h>
#define xiaowang 14
#define dawang 15
using namespace std;
const int maxn=1e3+10;
int T,n;
struct card{
	int num,col;
}a[maxn];
int cnt[maxn];
class check{
	bool single(){
		for(int i=1;i<=13;i++)
			if(cnt[i])
				return true;
		if(cnt[xiaowang]&&cnt[dawang])
			return true;
		return false;
	}
	bool two(){
		for(int i=1;i<=13;i++)
			if(cnt[i]==2)
				return true;
		return false;
	}
	bool three(){
		for(int i=1;i<=13;i++)
			if(cnt[i]==3)
				return true;
		return false;
	}
	bool three_one(){
		for(int i=1;i<=)
	}
}
int init(const string &s)
{
	if(s.size()==2){
		if(s[0]=='0'){
			if(s[1]=='1')
				return xiaowang;
			else return dawang;
		}
		else return 10+s[1]-'0';
	}else return s[0]-'0';
}
void dfs(int remind,int step){
	if(remind==0){
		ans=min(ans,step);
		return;
	}
	if(cnt[xiaowang]&&cnt[dawang]){//huojian
		cnt[xiaowang]--;
		cnt[dawang]--;
		dfs(remind-2,step+1);
		cnt[xiaowang]++;
		cnt[dawang]++;
	}
	for(int i=1;i<=13;i++)//boom
		if(cnt[i]==4){
			cnt[i]-=4;
			dfs(remind-4,step+1);
			cnt[i]+=4;
		}
	for(int i=1;i<=15;i++)//single
		if(cnt[i]==1){
			cnt[i]--;
			dfs(remind-1,step+1);
			cnt[i]++;
		}
	for(int i=1;i<=13;i++)//double
		if(cnt[i]==2){
			cnt[i]-=2;
			dfs(remind-2,step+1);
			cnt[i]+=2;
		}
	for(int i=1;i<=13;i++)//three
		if(cnt[i]==3){
			cnt[i]-=3;
			dfs(remind-3,step+1);
			cnt[i]+=3;
		}
	for(int i=1;i<=13;i++)//three and one
		if(cnt[i]==3){
			for(int j=1;j<=15;j++){
				if(j==i)continue;
				if(cnt[j]==1){
					cnt[i]-=3;
					cnt[j]-=1;
					dfs(remind-4,step+1);
					cnt[i]+=3;
					cnt[j]+=1;
				}
			}
		}
	for(int i=1;i<=13;i++)//three and two
		if(cnt[i]==3){
			for(int j=1;j<=13;j++){
				if(j==i)continue;
				if(cnt[j]==2){
					cnt[i]-=3;
					cnt[j]-=2;
					dfs(remind-5,step+1);
					cnt[i]+=3;
					cnt[j]+=2;
				}
			}
		}
	for(int i=3;i<=10;i++)
	
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		ans=0x7f7f7f7f;
		for(int i=1,col;i<=n;i++){
			string val;
			cin>>val>>col;
			a[i].num=init(val);
			a[i].col=col;
			book[init(val)]++;	
		}
		dfs(n,0);
		cout<<ans<<endl;
	}
}