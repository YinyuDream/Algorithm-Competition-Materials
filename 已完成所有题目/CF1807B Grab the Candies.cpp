#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,sum1,sum2;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		sum1=sum2=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]%2==0){
				sum1+=a[i];
			}else{
				sum2+=a[i];
			}
		}
		if(sum1>sum2){
			puts("YES");
		}else{
			puts("NO");
		}
	}
}