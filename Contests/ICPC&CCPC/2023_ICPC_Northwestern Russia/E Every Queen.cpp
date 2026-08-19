#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long 
int x[100500];
int y[100500];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		if(n==1){
			cout<<"Yes\n";
			cout<<x[0]<<' '<<y[0]<<'\n';
		}
		if(n==2){
			cout<<"Yes\n";
			cout<<x[0]<<' '<<y[1]<<'\n';
		}
		if(n>=3){
			//水平
		
			int l=1;
			for(;l<n;l++){
				if(y[l]==y[0]){
					continue;
				}
				else{
					break;
				}
			}
			if(l==n){
					cout<<"Yes\n";
					cout<<x[0]<<' '<<y[0]<<'\n';
					continue;
			}
			//水平
			int tx=x[l];
			int ty=y[0];
			int f=1;
			for(int i=l+1;i<n;i++){
				if(y[i]==ty||x[i]==tx){
					continue;
				}
				if(abs(tx-x[i])==abs(ty-y[i])){
					continue;
				}
				f=0;
				break;
			}
			if(f==1){
				cout<<"Yes\n";
				cout<<tx<<' '<<ty<<'\n';
				continue;
			}
			//斜线
			tx=x[l]+y[0]-y[l];
			ty=y[0];
			f=1;
			for(int i=l+1;i<n;i++){
				if(y[i]==ty||x[i]==tx){
					continue;
				}
				if(abs(tx-x[i])==abs(ty-y[i])){
					continue;
				}
				f=0;
				break;
			}
			if(f==1){
				cout<<"Yes\n";
				cout<<tx<<' '<<ty<<'\n';
				continue;
			}
			//反斜线
			tx=x[l]-y[0]+y[l];
			ty=y[0];
			f=1;
			for(int i=l+1;i<n;i++){
				if(y[i]==ty||x[i]==tx){
					continue;
				}
				if(abs(tx-x[i])==abs(ty-y[i])){
					continue;
				}
				f=0;
				break;
			}
			if(f==1){
				cout<<"Yes\n";
				cout<<tx<<' '<<ty<<'\n';
				continue;
			}
		
			
			//垂直
		
				l=1;
				for(;l<n;l++){
					if(x[l]==x[0]){
						continue;
					}
					else{
						break;
					}
				}
				if(l==n){
					cout<<"Yes\n";
					cout<<x[0]<<' '<<y[0]<<'\n';
					continue;
				}
				//水平
				ty=y[l];
				tx=x[0];
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				//斜线
				ty=y[l]+x[0]-x[l];
				tx=x[0];
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				//反斜线
				ty=y[l]-x[0]+x[l];
				tx=x[0];
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				
				
				l=1;
				for(;l<n;l++){
					if(x[l]-x[0]==y[l]-y[0]){
						continue;
					}
					else{
						break;
					}
				}
				if(l==n){
					cout<<"Yes\n";
					cout<<x[0]<<' '<<y[0]<<'\n';
					continue;
				}
				//水平
				ty=y[l];
				tx=x[0]+y[l]-y[0];
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				//垂直
				ty=y[0]-x[0]+x[l];
				tx=x[l];
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				//反斜线
				int p=(y[l]-y[0]+x[l]-x[0]);
				if(p%2==0){
				tx=x[0]+p/2;
				ty=y[0]+p/2;
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				}
				
				
				l=1;
				for(;l<n;l++){
					if(x[l]-x[0]==-y[l]+y[0]){
						continue;
					}
					else{
						break;
					}
				}
				if(l==n){
					cout<<"Yes\n";
					cout<<x[0]<<' '<<y[0]<<'\n';
					continue;
				}
				//水平
				ty=y[l];
				tx=x[0]-y[l]+y[0];
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				//垂直
				ty=y[0]+x[0]-x[l];
				tx=x[l];
				f=1;
				for(int i=l+1;i<n;i++){
					if(y[i]==ty||x[i]==tx){
						continue;
					}
					if(abs(tx-x[i])==abs(ty-y[i])){
						continue;
					}
					f=0;
					break;
				}
				if(f==1){
					cout<<"Yes\n";
					cout<<tx<<' '<<ty<<'\n';
					continue;
				}
				//反斜线
				p=(-y[l]+y[0]-x[l]+x[0]);
				if(p%2==0){
					tx=x[l]+p/2;
					ty=y[l]+p/2;
					f=1;
					for(int i=l+1;i<n;i++){
						if(y[i]==ty||x[i]==tx){
							continue;
						}
						if(abs(tx-x[i])==abs(ty-y[i])){
							continue;
						}
						f=0;
						break;
					}
					if(f==1){
						cout<<"Yes\n";
						cout<<tx<<' '<<ty<<'\n';
						continue;
					}
				}
				cout<<"No\n";
		}
	}
	return 0;
}