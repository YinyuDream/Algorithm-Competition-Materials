#include<bits/stdc++.h>
using namespace std;
int T;
int n,flag;
string a,b,c;
int main(){
	cin>>T;
	while(T--){
        flag=0;
        cin>>n>>a>>b>>c;
        for(int i=0;i<n;i++){
            if(b[i]!=c[i]&&a[i]!=c[i]){
                flag=1;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
	}
	return 0;
}