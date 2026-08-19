#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
int T,n;
char s[maxn],t[maxn];
int work(int l,int r)
{
    memset(t,0,sizeof(t));
    int len=r-l+1,ans=0;
    for(int i=l;i<=r;i++)
        t[i-l+1]=s[i];
    for(int i=1;i<=len;i++){
        if(t[i]=='1'){
            int dis=0;
            flag:;
            while(t[i]=='1'){
                i++;
                dis++;
            }
            if(t[i-1]=='1'&&t[i]=='0'&&t[i+1]=='1'&&dis%3!=0){
                t[i]='1';
                goto flag;
            }   
            i--;
            ans+=(dis-1)/3+1;
        }
    }
    return ans;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>(s+1);
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++){
                ans+=work(i,j);
                /*for(int k=i;k<=j;k++)
                    cout<<s[k];
                cout<<" ";
                cout<<work(i,j)<<endl;*/
            }
        cout<<ans<<endl;
    }
    return 0;
}