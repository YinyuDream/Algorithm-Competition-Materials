#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,flag;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        if(n%2==0){
            flag=0;
        }else{
            flag=1;
            n++;
        }
        for(int i=1;i<=n/2;i++){
            a[i*2-1]=n-i+1;
            a[i*2]=n/2-i+1;
        }
        if(flag==0){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
        }else{
            for(int i=2;i<=n;i++){
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
	}
	return 0;
}