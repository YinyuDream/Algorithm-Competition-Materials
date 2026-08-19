#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e6+10;
int T,n,cnt[26];
char s[maxn];
ull hashl[maxn],hashr[maxn],pw[maxn];
bool not_palindrome(int l,int r)
{
    ull lnum=hashl[r]-hashl[l-1]*pw[r-l+1];
    ull rnum=hashr[l]-hashr[r+1]*pw[r-l+1];
    return lnum!=rnum;
}
void work()
{
    hashr[n+1]=0;
    for(int i=1;i<=n;i++)
        hashl[i]=hashl[i-1]*131+s[i]-'a';
    for(int i=n;i;i--)
        hashr[i]=hashr[i+1]*131+s[i]-'a';
    if(not_palindrome(1,n)){
        cout<<"YES"<<endl<<1<<endl;
        for(int i=1;i<=n;i++)
            cout<<s[i];
        cout<<endl;
        return ;
    }
    for(int i=1;i<n;i++){
        if(not_palindrome(1,i)&&not_palindrome(i+1,n)){
            cout<<"YES"<<endl<<2<<endl;
            for(int j=1;j<=i;j++)
                cout<<s[j];
            cout<<" ";
            for(int j=i+1;j<=n;j++)
                cout<<s[j];
            cout<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    pw[0]=1;
    for(int i=1;i<maxn;i++)
        pw[i]=pw[i-1]*131;
    cin>>T;
    while(T--){
        int tot=0;
        cin>>(s+1);
        n=strlen(s+1);
        work();
    }
    return 0;
}