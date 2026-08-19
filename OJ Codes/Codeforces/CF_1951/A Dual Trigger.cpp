#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
char s[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>s+1;
        int sum=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='1')
                sum++;
        if(sum==2){
            bool flag=true;
            for(int i=1;i<n;i++){
                if(s[i]=='1'&&s[i+1]=='1')
                    flag=false;
            }
            if(flag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }
        if(sum%2==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}