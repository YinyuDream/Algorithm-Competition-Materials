#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,odd,even,cnt;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		odd=even=0,cnt=3;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]%2==1){
				odd++;
			}else{
				even++;
			}
		}
		if(odd>=3){
			puts("YES");
			for(int i=1;i<=n&&cnt;i++){
				if(a[i]%2==1){
					cout<<i<<" ";
					cnt--;
				}
			}
			puts("");
		}else if(odd==2&&n>=4){
			puts("YES");
			for(int i=1;i<=n&&cnt>2;i++){
				if(a[i]%2==1){
					cout<<i<<" ";
					cnt--;
				}
			}
			for(int i=1;i<=n&&cnt;i++){
				if(a[i]%2==0){
					cout<<i<<" ";
					cnt--;
				}
			}
			puts("");
		}else if(odd==1){
			puts("YES");
			for(int i=1;i<=n&&cnt>2;i++){
				if(a[i]%2==1){
					cout<<i<<" ";
					cnt--;
				}
			}
			for(int i=1;i<=n&&cnt;i++){
				if(a[i]%2==0){
					cout<<i<<" ";
					cnt--;
				}
			}
			puts("");
		}else{
			puts("NO");
		}
	}
	return 0;
}