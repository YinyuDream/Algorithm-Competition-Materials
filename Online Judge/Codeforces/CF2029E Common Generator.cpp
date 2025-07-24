#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+10;
int prime[maxn],not_prime[maxn],cnt;
void init(){
    for(int i=2;i<maxn;i++){
        if(!not_prime[i]){
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int val=0,mn=1e9;
    for(int i=0;i<n;i++){
        if(!not_prime[a[i]]){
            if(val>0&&val!=a[i]){
                cout<<-1<<endl;
                return ;
            }
            val=a[i];
            continue;
        }
        if(a[i]%2==0){
            mn=min(mn,a[i]/2);
        }
        else{
            for(int j=2;j<maxn;j++){
                if(a[i]%j==0){
                    mn=min(mn,(a[i]-j)/2);
                    break;  
                }
            }
        }
        
    }
    if(val==0){
        cout<<2<<endl;
    }else{
        if(mn>=val){
            cout<<val<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}
int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}