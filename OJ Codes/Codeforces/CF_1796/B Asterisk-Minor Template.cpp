#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m;
char s1[maxn],s2[maxn];
int main(){
    cin>>T;
    while(T--){
        bool flag=0;
        cin>>(s1+1)>>(s2+1);
        n=strlen(s1+1);
        m=strlen(s2+1);
        for(int i=1;i<n&&flag==0;i++){
            for(int j=1;j<m&&flag==0;j++){
                if(s1[i]==s2[j]&&s1[i+1]==s2[j+1]){
                    cout<<"YES"<<endl<<'*'<<s1[i]<<s1[i+1]<<'*'<<endl;
                    flag=1;
                }
            }
        }
        if(flag==1)
            continue;
        if(s1[1]==s2[1])
            cout<<"YES"<<endl<<s1[1]<<'*'<<endl;
        else if(s1[n]==s2[m])
            cout<<"YES"<<endl<<'*'<<s1[n]<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}