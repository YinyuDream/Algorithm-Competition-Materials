#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll p=998244353;
int n,m;
struct martix{
    int id;
    ll num[2][2];
    martix(int num00,int num01,int num10,int num11,int _id){
        num[0][0]=num00;
        num[0][1]=num01;
        num[1][0]=num10;
        num[1][1]=num11;
        id=_id;
    }
    martix(){
        num[0][0]=num[1][1]=num[0][1]=num[1][0]=0;
        id=0;
    }
}a[maxn];
martix operator*(martix a,martix b){
    martix c(0,0,0,0,0);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
                c.num[i][j]%=p;
            }
        }
    }
    return c;
}
deque<martix> q;
void work(int l,int r)
{
    int cnt=0;
    while(!q.empty()) q.pop_front();
    for(int i=l;i<=r;i++){
        if(a[i].id==1){
            q.push_front(martix(a[i].num[0][0],a[i].num[0][1],a[i].num[1][0],a[i].num[1][1],++cnt));
        }else if(a[i].id==2){
            q.push_back(martix(a[i].num[0][0],a[i].num[0][1],a[i].num[1][0],a[i].num[1][1],++cnt));
        }else{
            if(q.size()){
                if(q.front().id>q.back().id)q.pop_front();
                else q.pop_back();
            }
        }
    }
    martix ans(1,0,0,1,3);
    for(auto i:q)
        ans=ans*i;
    cout<<ans.num[0][0]<<" "<<ans.num[0][1]<<" "<<ans.num[1][0]<<" "<<ans.num[1][1]<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=1,opt;i<=n;i++){
        cin>>opt;
        if(opt==1||opt==2){
            int num00,num01,num10,num11;
            cin>>num00>>num01>>num10>>num11;
            a[i]=martix(num00,num01,num10,num11,opt);
        }else{
            a[i]=martix(0,0,0,0,3);
        }
    }
    for(int i=1,v;i<=m;i++){
        cin>>v;
        if(v==1){
            int pos,opt;
            cin>>pos>>opt;
                if(opt==1||opt==2){
                int num00,num01,num10,num11;
                cin>>num00>>num01>>num10>>num11;
                a[pos]=martix(num00,num01,num10,num11,opt);
            }else{
                a[pos]=martix(0,0,0,0,3);
            }
        }else{
            int l,r;
            cin>>l>>r;
            work(l,r);
        }
    }
    return 0;
}