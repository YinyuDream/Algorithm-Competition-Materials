#include<bits/stdc++.h>
using namespace std;
int T,n,x,a,b;
set<int>ans;
int main(){
	cin>>T;
	while(T--){
        ans.clear();
		cin>>n>>x;
        for(int i=1;i<=sqrt(n-x);i++){
            if((n-x)%i==0){
                if(i%2==0&&(i+2)/2>=x){
                    ans.insert((i+2)/2);
                }
                int val=(n-x)/i;
                if(val%2==0&&(val+2)/2>=x){
                    ans.insert((val+2)/2);
                }
            }
        }
        for(int i=1;i<=sqrt(n+x-2);i++){
            if((n+x-2)%i==0){
                if(i%2==0&&(i+2)/2>=x){
                    ans.insert((i+2)/2);
                }
                int val=(n+x-2)/i;
                if(val%2==0&&(val+2)/2>=x){
                    ans.insert((val+2)/2);
                }
            }
        }
        cout<<ans.size()<<endl;
	}
	return 0;
}