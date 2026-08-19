#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m;
int a[maxn],sum[maxn];
char s[maxn];
ll tot;
deque<int>q;
void add(int pos,int num)
{
    for(int i=pos;i<=n;i+=i&-i)
        sum[i]+=num;
}
int query(int pos)
{
    int ans=0;
    for(int i=pos;i;i-=i&-i)
        ans+=sum[i];
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        tot+=query(a[i]-1);
        add(a[i],1);
    }
    tot=(ll)n*(n-1)/2-tot;
    cout<<tot<<endl;
    for(int i=1;i<=n;i++)
        q.push_back(a[i]);
    cin>>s+1;
    int rev=0;
    for(int i=1;i<=m;i++){
        if(s[i]=='R'){
            rev^=1;
            tot=(ll)n*(n-1)/2-tot;
        }else{
            if(rev==0){
                tot=tot-(q.front()-1)+(n-q.front());
                q.push_back(q.front());
                q.pop_front();
            }else{
                tot=tot-(q.back()-1)+(n-q.back());
                q.push_front(q.back());
                q.pop_back();
            }
        }
        cout<<tot%10;
    }
    return 0;
}