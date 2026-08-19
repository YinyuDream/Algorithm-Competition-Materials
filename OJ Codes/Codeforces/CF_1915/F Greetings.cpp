#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,a[maxn],b[maxn];
int c[maxn],help[maxn],tree[maxn];
long long ans;
struct node{
    int l,r;
}p[maxn];
bool cmp(node a,node b)
{
    return a.r<b.r;
}
void lsh()
{
	for(int i=1;i<=n*2;i++)
		help[i]=c[i];
	sort(help+1,help+n*2+1);
	int cnt=unique(help+1,help+n*2+1)-help-1;
	for(int i=1;i<=n*2;i++)
		c[i]=lower_bound(help+1,help+cnt+1,c[i])-help;
}
void update(int x,int val){
	while(x<=n*2)tree[x]+=val,x+=(x&-x);
}
int deqre(int x){
	int ans=0;
	while(x>0)ans+=tree[x],x-=(x&-x);
	return ans;
}
int main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n*2;i++)
           tree[i]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i],c[i*2-1]=a[i],c[i*2]=b[i];
        lsh();
        for(int i=1;i<=n;i++)
            p[i]={c[i*2-1],c[i*2]};
        sort(p+1,p+n+1,cmp);
        update(1,1);
        update(p[1].l+1,-1);
        for(int i=2;i<=n;i++){
            ans+=deqre(p[i].l);
            update(1,1);
            update(p[i].l+1,-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}