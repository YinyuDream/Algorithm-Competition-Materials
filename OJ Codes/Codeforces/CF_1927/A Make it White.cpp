#include<bits/stdc++.h>
using namespace std;
int T,n,p1,p2;
char s[15];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s+1;
        p1=p2=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='B'){
                p1=i;
                break;
            }
        for(int i=n;i;i--)
            if(s[i]=='B'){
                p2=i;
                break;
            }
        cout<<p2-p1+1<<endl;
	}
	return 0;
}