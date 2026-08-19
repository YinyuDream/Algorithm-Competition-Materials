#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m;
struct node{
    int l,r,w;
}a[maxn];
int p[maxn],book[maxn];
stack<node>st;
vector<node>vec;
bool operator<(node u,node v)
{
    if(u.r!=v.r)return u.r<v.r;
    else return u.l>v.l;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        p[i]=i;
    for(int i=1;i<=m;i++){
        cin>>a[i].l>>a[i].r>>a[i].w;
        if(a[i].l==a[i].r&&a[i].w==1){
            cout<<-1;
            return 0;
        }
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        bool flag=true;
        for(int j=a[i].l;j<=a[i].r;j++){
            if(book[j]){
                flag=false;
                break;
            }
        }
        if(flag==true){
            if(a[i].w==1&&a[i].l!=a[i].r)
                swap(p[a[i].l],p[a[i].l+1]);
            for(int j=a[i].l;j<=a[i].r;j++)
                book[j]=true;
            st.push({a[i].l,a[i].r,a[i].w});
            continue;
        }
        int val=0;
        vec.clear();
        while(st.size()&&st.top().l>=a[i].l){
            val+=st.top().w;
            vec.push_back(st.top());
            st.pop();
        }
        st.push({a[i].l,a[i].r,a[i].w});
        reverse(vec.begin(),vec.end());
        if((a[i].w+val)%2==0){
            for(int j=a[i].l;j<=a[i].r;j++)
                book[j]=1;
            continue;
        }
        if(book[a[i].l]==0&&book[a[i].r]==1){
            int pos=0;
            for(int j=a[i].l;j<=a[i].r;j++){
                if(book[j]==0&&book[j+1]==1){
                    pos=j;
                    break;
                }
            }
            for(int j=a[i].l;j<=a[i].r;j++){
                if(p[j]==p[pos]+1){
                    swap(p[j],p[pos]);
                    break;
                }
            }
        }else if(book[a[i].r]==0){
            int pos=0;
            for(int j=a[i].r;j>=a[i].l;j--){
                if(book[j]==0&&book[j-1]==1){
                    pos=j;
                    break;
                }
            }
            for(int j=a[i].l;j<=a[i].r;j++){
                if(p[j]==p[pos]-1){
                    swap(p[j],p[pos]);
                    break;
                }
            }
        }else{
            int pos1=0,pos2=0,mx1=0,mx2=n;
            for(int j=vec[0].l;j<=vec[0].r;j++){
                if(mx1<p[j]){
                    mx1=p[j];
                    pos1=j;
                }
            }
            for(int j=vec[1].l;j<=vec[1].r;j++){
                if(mx2>p[j]){
                    mx2=p[j];
                    pos2=j;
                }
            }
            if(vec[0].r+1==vec[1].l)
                swap(p[pos1],p[pos2]);
            else swap(p[pos1],p[vec[0].r+1]);
        }
        for(int j=a[i].l;j<=a[i].r;j++)
            book[j]=1;
    }
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
    return 0;
}