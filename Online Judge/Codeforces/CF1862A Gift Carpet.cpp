#include<bits/stdc++.h>
using namespace std;
int T,n,m;
char s[21][21];
int find(int x, char ch)
{
    if(x>m)return -1;
    for(int i=x;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[j][i]==ch){
                return i;
            }
        }
    }
    return -1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>(s[i]+1);
        int p1=find(1,'v');
        if(p1==-1){
            cout<<"NO"<<endl;
            continue;
        }
        int p2=find(p1+1,'i');
        if(p2==-1){
            cout<<"NO"<<endl;
            continue;
        }
        int p3=find(p2+1,'k');
        if(p3==-1){
            cout<<"NO"<<endl;
            continue;
        }
        int p4=find(p3+1,'a');
        if(p4==-1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
	}
	return 0;
}