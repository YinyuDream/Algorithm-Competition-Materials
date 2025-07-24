#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[1]-=1;
	for(int i=2;i<=n;i++){
		if(a[i]-i<=a[i-1]){
			a[i]=a[i-1]+1;
		}else{
			a[i]-=i;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}