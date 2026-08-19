#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,t,q,sum;
char s[3][maxn];
queue<pair<int,int> >que;
int main(){
	cin>>T;
	while(T--){
		while(que.size())que.pop();
		sum=0;
		cin>>s[1]+1>>s[2]+1>>t>>q;
		int n=strlen(s[1]+1);
		for(int i=1;i<=n;i++)
			if(s[1][i]!=s[2][i])
				sum++;
		for(int i=1,opt,a,b,c,d;i<=q;i++){
			if(que.size()&&que.front().second+t<=i){
				int t=que.front().first;
				if(s[1][t]!=s[2][t])sum++;
				que.pop();
				
			}
			cin>>opt;
			if(opt==1){
				cin>>a;
				if(s[1][a]!=s[2][a])sum--;
				que.push(make_pair(a,i));
			}else if(opt==2){
				cin>>a>>b>>c>>d;
				int tmp=(s[1][b]!=s[2][b])+(s[1][d]!=s[2][d]);
				swap(s[a][b],s[c][d]);
				int tmp2=(s[1][b]!=s[2][b])+(s[1][d]!=s[2][d]);
				sum+=tmp2-tmp;
			}else{
				if(!sum)puts("YES");
				else puts("NO");
			}
		}
	}
}