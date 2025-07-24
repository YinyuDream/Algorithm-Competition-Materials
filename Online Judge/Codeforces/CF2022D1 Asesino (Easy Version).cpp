#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    auto ask=[&](int u,int v){
        cout<<"? "<<u<<" "<<v<<endl;
        cout.flush();
        int x;
        cin>>x;
        return x;
    };
    int pos=-1;
    for(int i=2;i<=n;i+=2){
        int u=ask(i-1,i);
        int v=ask(i,i-1);
        if(u!=v){
            pos=i-1;
            break;
        }
    }
    if(pos==-1){
        cout<<"! "<<n<<endl;
        cout.flush();
        return ;
    }
    int now=-1;
    for(int i=1;i<=n;i++){
        if(i!=pos&&i!=pos+1){
            now=i;
            break;
        }
    }
    int u=ask(pos,now);
    int v=ask(now,pos);
    if(u!=v){
        cout<<"! "<<pos<<endl;
    }else{
        cout<<"! "<<pos+1<<endl;
    }
    cout.flush();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}