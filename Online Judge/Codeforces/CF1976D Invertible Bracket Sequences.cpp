#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T,n,sum;
int pre[maxn],suf[maxn];
int mn_pre[maxn],mn_suf[maxn];
int mx_suf[maxn][21];
void init()
{
    for(int i=0;i<=20;i++)
        mx_suf[n+1][i]=0;
    for(int i=1;i<=n;i++)
        mx_suf[i][0]=suf[i];
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            mx_suf[i][j]=max(mx_suf[i][j-1],mx_suf[i+(1<<(j-1))][j-1]);
}
int query(int l,int r)
{
    int k=log2(r-l+1);
    return max(mx_suf[l][k],mx_suf[r-(1<<k)+1][k]);
}
bool check(int l,int r,string &s)
{
    string t=s;
    for(int i=l;i<=r;i++)
        if(s[i]=='(') t[i]=')';
        else t[i]='(';
    int val=0;
    for(int i=0;i<n;i++){
        if(t[i]=='(') val++;
        else val--;
        if(val<0) return false;
    }
    return val==0;
}
int find(int pos_l)
{
    int pos_r=n;
    int l=pos_l,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(query(pos_l,mid+1)<=suf[pos_l]+pre[pos_l-1]&&mn_suf[mid+1]>=0)l=mid+1;
        else r=mid-1;
    }
    if(r<pos_l) return -1;
    return pos_r=r;
}
map<int,vector<int>>mp;
int main(){
    cin>>T;
    while(T--){
        mp.clear();
        sum=0;
        string s;
        cin>>s;
        n=s.size();
        s=' '+s;
        ll ans=0;
        for(int i=1;i<=n;i++){
            sum+=(s[i]=='('?1:-1);
            if(mp.find(sum)==mp.end()){
                vector<int> vec;
                vec.push_back(i);
                mp.insert(make_pair(sum,vec));
            }else{
                mp[sum].push_back(i);
            }
        }
        if(sum%2==1){
            cout<<0<<endl;
            continue;
        }
        pre[1]=(s[1]=='('?1:-1);
        mn_pre[1]=pre[1];
        for(int i=2;i<=n;i++){
            pre[i]=pre[i-1]+(s[i]=='('?1:-1);
            mn_pre[i]=min(mn_pre[i-1],pre[i]);
        }
        suf[n+1]=mn_suf[n+1]=0;
        suf[n]=s[n]==')'?1:-1;
        mn_suf[n]=suf[n];
        for(int i=n-1;i>=1;i--){
            suf[i]=suf[i+1]+(s[i]==')'?1:-1);
            mn_suf[i]=min(mn_suf[i+1],suf[i]);
        }
        init();
        for(int i=1;i<=n;i++){
            if(mn_pre[i-1]<0)break;
            int r=find(i);
            if(r==-1) continue;
            auto it=mp.find(sum/2+pre[i-1]);
            if(it==mp.end())
                continue;
            vector<int> &vec=it->second;
            auto low=lower_bound(vec.begin(),vec.end(),i);
            auto high=upper_bound(vec.begin(),vec.end(),r);
            high--;
            ans+=high-low+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}