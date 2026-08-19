#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a,b(n),book(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(book[i]) continue;
        for(int j=i+1;j<n;j++)
            if(b[j]%b[i]==0)
                book[j]=1;
    }
    for(int i=0;i<n;i++)
        if(!book[i])
            a.push_back(b[i]);
    int ans=n-a.size();
    n=a.size();
    if(n==1){
        cout<<0+ans<<endl;
        return ;
    }else if(n==2){
        cout<<1+(a[1]%a[0]!=0)+ans<<endl;
        return ;
    }
    bool can=true;
    for(int i=1;i<n;i++){
        can&=(a[i]%a[0]==0);
    }
    if(can){
        cout<<n-1+ans<<endl;
        return ;
    }
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            can=true;
            int val=b[j]%b[i];
            if(val==0) continue;
            for(int k=0;k<n;k++){
                if(k!=j){
                    can&=(b[k]%val==0);
                }
            }
            if(can){
                cout<<n+ans<<endl;
                return ;
            }
            can=true;
            int origin=a[j];
            a[j]=val;
            for(int k=1;k<n;k++){
                can&=(a[k]%a[0]==0);
            }
            if(can){
                cout<<n+ans<<endl;
                return ;
            }
            a[j]=origin;
        }
    }
    int cnt=0;
    for(int i=1;i<n;i++)
        cnt+=(a[i]%a[0]!=0);
    if(cnt<=1){
        cout<<n+ans<<endl;
        return ;
    }

    int gcd=a[1];
    for(int i=2;i<n;i++){
        gcd=__gcd(gcd,a[i]);
    }
    if(a[0]<=gcd){
        cout<<n+ans<<endl;
        return ;
    }
    if(a[2]!=a[0]){
        int tot=0;
        for(int i=2;i<n;i++)
            tot+=(a[i]%a[1]!=0);
        if(tot==0){
            cout<<n+ans<<endl;
            return ;
        }
    }
    cout<<n+1+ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}