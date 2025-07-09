#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,tot=1;
string s[maxn];
struct node{
    int val,child[26];
}trie[maxn];
void insert_trie(string s){
    int len=s.size(),now=1;
    for(int i=0;i<len;i++){
        trie[now].val++;
        int c=s[i]-'a';
        if(!trie[now].child[c]) trie[now].child[c]=++tot;
        now=trie[now].child[c];
    }
    trie[now].val++;
}
ll work(string s){
    int len=s.size(),now=1;
    ll ans=0;
    for(int i=0;i<len;i++){
        int c=s[i]-'a';
        if(trie[now].child[c]!=0){
            ans+=(1ll*trie[now].val-trie[trie[now].child[c]].val)*(len-i);
            now=trie[now].child[c];
        }else{
            ans+=1ll*trie[now].val*(len-i);
            break;
        }
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        insert_trie(s[i]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        reverse(s[i].begin(),s[i].end());
        ans+=work(s[i]);
        reverse(s[i].begin(),s[i].end());
    }
    memset(trie,0,sizeof(trie));
    tot=1;
    for(int i=1;i<=n;i++){
        reverse(s[i].begin(),s[i].end());
        insert_trie(s[i]);
        reverse(s[i].begin(),s[i].end());
    }
    for(int i=1;i<=n;i++){
        ans+=work(s[i]);
    }
    cout<<ans;
    return 0;
}