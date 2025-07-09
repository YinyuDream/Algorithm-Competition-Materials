#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,d,flag;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		flag=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			char ch=getchar();
			while(ch<'0'||ch>'9')ch=getchar();
			a[i]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			if(d>a[i]&&!flag)cout<<d,flag=1;
			cout<<a[i];
		}
		if(!flag)cout<<d;
		cout<<endl;
	}
	return 0;
}