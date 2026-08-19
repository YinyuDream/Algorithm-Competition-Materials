#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,sum_1,sum_2,cnt;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		sum_1=sum_2=cnt=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum_1++;
			else sum_2++;
		}
		if(sum_2%2!=0)cnt++,sum_2--,sum_1++;
		while(sum_2>sum_1)sum_2-=2,sum_1+=2,cnt+=2;
		cout<<cnt<<endl;
	}
	return 0;
}