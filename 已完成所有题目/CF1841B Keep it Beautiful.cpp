#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
		int top=0,flag=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			if(!top){
				b[++top]=a[i];
				cout<<1;
				continue;
			}
			if(a[i]>=b[top]){
				if(flag==0){
					b[++top]=a[i];
					cout<<1;
					continue;
				}else{
					if(a[i]<=b[1]){
						b[++top]=a[i];
						cout<<1;
						continue;
					}
				}
			}else{
				if(a[i]<=b[1]&&flag==0){
					b[++top]=a[i];
					cout<<1;
					flag=1;
					continue;
				}
			}
			cout<<0;
		}
		cout<<endl;
	}
	return 0;
}