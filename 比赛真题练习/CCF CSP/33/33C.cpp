#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
void work()
{
	map<string,int>mp;
	int n,cnt=0;
	double matrix[101][101];
	memset(matrix,0,sizeof matrix);
	cin>>n;
	for(int k=1;k<=n;k++){
		string s;
		cin>>s;
		auto lst=s.begin();
		for(auto i=s.begin();i!=s.end();i++){
			if(*i>='0'&&*i<='9'&&*(i-1)>='a'&&*(i-1)<='z'){
				string u;
				for(auto j=lst;j<i;j++)
					u.push_back(*j);
				if(mp.find(u)==mp.end())
					mp.insert(make_pair(u,++cnt));
				auto pos=i;
				while(pos!=s.end()&&*pos<='9'&&*pos>='0')pos++;
				pos--;
				int val=0;
				if(pos==i)val=(*i)-'0';
				if(pos==i+1)val=((*i)-'0')*10+(*pos)-'0';
				matrix[mp[u]][k]=val;
				lst=pos+1;
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){//第i列
		
		bool flag=false;
		for(int j=mx+1;j<=cnt;j++){
			if(abs(matrix[j][i])>eps)
				flag=true;
		}
		if(flag==false)continue;
		int pos=i;
		if(abs(matrix[mx+1][i])<eps){
			for(int j=mx+2;j<=cnt;i++){
				if(abs(matrix[j][i])>eps){
					pos=j;
					goto flag;
				}
			}
		}
		flag:;
		for(int j=1;j<=n;j++){
			swap(matrix[mx+1][j],matrix[pos][j]);
		}
		for(int j=mx+2;j<=cnt;j++){
			if(abs(matrix[j][i])>eps){
				double tme=matrix[mx+1][i]/matrix[j][i];
				for(int col=i;col<=n;col++){
					matrix[j][col]*=tme;
					matrix[j][col]-=matrix[mx+1][col];
				}
			}
		}
		mx++;
	}
	int num=0;
	for(int i=1;i<=cnt;i++){
		int flag=0;
		for(int j=1;j<=n;j++)
			if(abs(matrix[i][j])>eps){
				flag=1;
				break;
			}
		num+=flag;
	}
	if(num<n)cout<<"Y"<<endl;
	else cout<<"N"<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
} 