#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,a,b;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a<b)swap(a,b);
        int lim=2*sqrt((a+b));
        int ans=2e9;
        for(int i=1;i<=lim;i++){
            int num=i+b/i+a/i-1;
            if(b%i!=0)num++;
            if(a%i!=0)num++;
            ans=min(ans,num);
        }
        cout<<ans<<endl;
    }
    return 0;
}