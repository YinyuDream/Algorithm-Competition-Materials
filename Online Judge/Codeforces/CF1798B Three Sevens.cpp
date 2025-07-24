#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int mx[maxn];
vector<int> a[maxn];
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i].clear();
	for(int i=1,p;i<=n;i++){
		cin>>p;
		for(int j=1,t;j<=p;j++){
			cin>>t;
			a[i].push_back(t);
			mx[t]=i;
		}
	}
}
void work()
{
	for(int i=1;i<=n;i++){
		int size=a[i].size();
		for(unsigned int j=0;j<a[i].size();j++){
			if(mx[a[i][j]]!=i){
				size--;
				a[i][j]=0;
			}
		}
		if(size==0){
			cout<<-1<<endl;
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		for(unsigned int j=0;j<a[i].size();j++){
			if(a[i][j]!=0){
				cout<<a[i][j]<<" ";
				break;
			}
		}
	}
	cout<<endl;
	return ;
}
int main(){
	cin>>T;
	while(T--){
		init();
		work();
	}
	return 0;
}