#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<n;i++){
			cin>>b[i];
			a[i]=-1;
		}
		a[n]=-1,a[1]=b[1];
		for(int i=2;i<n;i++){
			if(a[i]==-1&&b[i-1]>=b[i]){
				a[i]=b[i];
			}else if(a[i]<b[i]){
				a[i+1]=b[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1){
				a[i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}