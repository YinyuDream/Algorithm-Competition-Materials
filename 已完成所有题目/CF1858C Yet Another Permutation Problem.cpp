#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,N=1e5;
int T,n,top;
int book[maxn],ans[maxn];
void work(){
    for(int i=1;i<=N;i++){
        if(book[i]==0){
            for(int j=0;i*(1<<j)<=N;j++){
                ans[++top]=i*(1<<j);
                book[i*(1<<j)]=1;
            }
        }
    }
}
int main(){
	cin>>T;
    work();
	while(T--){
		cin>>n;
        for(int i=1;i<=top;i++){
            if(ans[i]<=n){
                cout<<ans[i]<<" ";
            }
        }
        for(int i=1;i<=n;i++){
            if(book[i]==0){
                cout<<i<<" ";
            }
        }
        cout<<endl;
	}
	return 0;
}