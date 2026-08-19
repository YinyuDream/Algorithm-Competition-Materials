#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                cout<<char(j+'a');
            }
        }
        cout<<endl;
	}
	return 0;
}