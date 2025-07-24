#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int T,n,k,ans,max_id;
int a[maxn],b[maxn];
struct tire{
    int son[2];
}tree[maxn<<3];
void update(int num){
    int id=0;
    for(int i=7;i>=0;i--){
        int t=(num>>i)&1;
        if(tree[id].son[t]==0){
            k++;
            tree[id].son[t]=k;
        }
        id=tree[id].son[t];
        max_id=max(max_id,id);
    }
    
}
int find(int num)
{
    int ans=0,id=0;
    for(int i=7;i>=0;i--){
        int t=!((num>>i)&1);
        if(tree[id].son[t]){
            id=tree[id].son[t];
            ans+=t<<i;
        }else if(tree[id].son[t^1]){
            id=tree[id].son[t^1];
            ans+=(t^1)<<i;
        }
    }
    return ans;
}
int main(){
	cin>>T;
	while(T--){
        for(int i=0;i<=max_id;i++)
            tree[i].son[0]=tree[i].son[1]=0;
        ans=k=max_id=0;
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],b[i]=0,ans=max(ans,a[i]);
        b[1]=a[1],update(b[1]),update(0);
        for(int i=2;i<=n;i++)
            b[i]=b[i-1]^a[i],update(b[i]);
        for(int i=0;i<=n;i++)
            ans=max(ans,b[i]^b[n]);
        for(int i=0;i<=n;i++)
            ans=max(ans,b[i]^find(b[i]));
        cout<<ans<<endl;
	}
	return 0;
}