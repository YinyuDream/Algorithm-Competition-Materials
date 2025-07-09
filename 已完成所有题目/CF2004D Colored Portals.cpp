#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char,char> pii;
const int maxn=1e6+10;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> col(n+1);
    map<string,vector<int>> mp;
    for(int i=1;i<=n;i++){
        cin>>col[i];
        mp[col[i]].push_back(i);
    }
    auto intersect=[&](string t1,string t2){
        set<char> set_t1 = {t1[0], t1[1]};
        set<char> set_t2 = {t2[0], t2[1]};
        set<char> chars_to_check = {'B', 'G', 'R', 'Y'};
        bool found = false;
        for (char ch : chars_to_check) {
            if (set_t1.find(ch) != set_t1.end() && set_t2.find(ch) != set_t2.end()) {
                found = true;
                break;
            }
        }
        return found;
    };
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        if(l>r){
            swap(l,r);
        }
        if(intersect(col[l],col[r])){
            cout<<r-l<<endl;
        }else{
            set<string> st={"BG","BR","BY","GR","GY","RY"};
            int ans=1e9;
            for(auto x:st){
                if(x==col[l]||x==col[r]){
                    continue;
                }
                if(mp[x].size()==0){
                    continue;
                }
                int pos1=lower_bound(mp[x].begin(),mp[x].end(),l)-mp[x].begin();
                if(pos1<mp[x].size())
                    ans=min(ans,mp[x][pos1]-l+abs(mp[x][pos1]-r));
                int pos2=lower_bound(mp[x].begin(),mp[x].end(),r)-mp[x].begin();
                if(pos2-1>=0)
                    ans=min(ans,r-mp[x][pos2-1]+abs(mp[x][pos2-1]-l));
            }
            if(ans==1e9){
                cout<<-1<<endl;
            }else{
                cout<<ans<<endl;
            }
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}