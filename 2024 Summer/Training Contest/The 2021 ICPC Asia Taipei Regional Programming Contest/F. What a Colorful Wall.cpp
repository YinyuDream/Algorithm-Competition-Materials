#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+10;
int n;
struct rec{
    int x1,y1,x2,y2,col;
}a[maxn];
bool operator <(const rec &a,const rec &b){
    return a.y1<b.y1;
}
int help[maxn],c[maxn];
void lsh(){
    for(int i=1;i<=n*2;i++)
        help[i]=c[i];
    sort(help+1,help+n*2+1);
    int tot=unique(help+1,help+n*2+1)-help-1;
    for(int i=1;i<=n*2;i++)
        c[i]=lower_bound(help+1,help+tot+1,c[i])-help;
}
class segment_tree{
    public:
        int lef[maxn<<8],rig[maxn<<8],minx[maxn<<8],lazy[maxn<<8];
    segment_tree(){
        memset(lef,0,sizeof(lef));
        memset(rig,0,sizeof(rig));
        memset(minx,0,sizeof(minx));
        memset(lazy,0,sizeof(lazy));
    }
    void build(int l,int r,int id,int val)
    {
        lef[id]=l;
        rig[id]=r;
        if(l==r)
        {
            minx[id]=val;
            lazy[id]=0;
            lef[id]=rig[id]=0;
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,id<<1,val);
        build(mid+1,r,id<<1|1,val);
        minx[id]=min(minx[id<<1],minx[id<<1|1]);
        lazy[id]=0;
    }
    void pushdown(int id)
    {
        if(lazy[id])
        {
            minx[id<<1]=minx[id<<1|1]=lazy[id];
            lazy[id<<1]=lazy[id<<1|1]=lazy[id];
            lazy[id]=0;
        }
    }
    void update(int l,int r,int id,int val)
    {
        if(lef[id]>=l&&rig[id]<=r)
        {
            minx[id]=lazy[id]=val;
            return;
        }
        pushdown(id);
        int mid=(lef[id]+rig[id])>>1;
        if(l<=mid)
            update(l,r,id<<1,val);
        if(r>mid)
            update(l,r,id<<1|1,val);
        minx[id]=min(minx[id<<1],minx[id<<1|1]);
    }
    int query(int l,int r,int id)
    {
        if(lef[id]>=l&&rig[id]<=r)
            return minx[id];
        pushdown(id);
        int mid=(lef[id]+rig[id])>>1;
        int ans=0x3f3f3f3f;
        if(l<=mid)
            ans=min(ans,query(l,r,id<<1));
        if(r>mid)
            ans=min(ans,query(l,r,id<<1|1));
        return ans;
    }
};
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].col;
        swap(a[i].y1,a[i].y2);
    }
    for(int i=1;i<=n;i++){
        c[i*2-1]=a[i].y1;
        c[i*2]=a[i].y2;
    }
    lsh();
    for(int i=1;i<=n;i++){
        a[i].y1=c[i*2-1];
        a[i].y2=c[i*2];
    }
    for(int i=1;i<=n;i++){
        c[i*2-1]=a[i].x1;
        c[i*2]=a[i].x2;
    }
    lsh();
    for(int i=1;i<=n;i++){
        a[i].x1=c[i*2-1];
        a[i].x2=c[i*2];
    }
    set<rec>st;
    set<int>col;
    st.insert(a[n]),col.insert(a[n].col);
    for(int i=n-1;i;i--){
        
        bool flag=true;
        segment_tree t;
        t.build(a[i].x1,a[i].x2-1,1,a[i].y1-1);
        for(auto it=st.begin();it!=st.end();it++){
            int x1=max(a[i].x1,it->x1),x2=min(a[i].x2-1,it->x2-1);
            if(x1>x2)continue;
            int ans=t.query(x1,x2,1);
            if(ans<it->y1-1){
                flag=false;
                break;
            }
            t.update(x1,x2,1,it->y2-1);
        }
        if(t.query(a[i].x1,a[i].x2-1,1)<a[i].y2-1){
            col.insert(a[i].col);
        }
        st.insert(a[i]);
    }
    cout<<col.size()<<endl;
    return 0;
}