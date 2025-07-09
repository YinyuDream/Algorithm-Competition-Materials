#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m;
int cnt[maxn],cnt2[maxn],book[maxn][maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			int word;
			cin>>word;
			cnt[word]++;
			if(!book[i][word]){
				book[i][word]=1;
				cnt2[word]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt2[i]<<" "<<cnt[i]<<endl;
	return 0;
} 