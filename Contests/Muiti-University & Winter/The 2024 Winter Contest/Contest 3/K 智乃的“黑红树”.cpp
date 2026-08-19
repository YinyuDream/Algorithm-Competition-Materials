#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,a,b,k;
int child_l[maxn],child_r[maxn];
struct node{
    int id,col;
    node(int _id,int _col){
        id=_id,col=_col;
    }
};
queue<node>q;
int main(){
    cin>>T;
    while(T--){
        k=1;
        cin>>a>>b;
        for(int i=1;i<=a+b;i++){
            child_l[i]=child_r[i]=-1;
        }
        if(a%2==0||b%2==1||b>a*2||b<(a+1)/4*2){
            cout<<"No"<<endl;
            continue;
        }
        if(a==1&&b==0){
            cout<<"Yes"<<endl<<"-1 -1"<<endl;
            continue;
        }
        q.empty();
        q.push(node(1,0));
        a--;
        while(a>0||b>0){
            node u=q.front();
            q.pop();
            if(u.col==1&&a>0){
                q.push(node(++k,0));
                child_l[u.id]=k;
                q.push(node(++k,0));
                child_r[u.id]=k;
                a-=2;
            }else if(u.col==0&&b>0){
                q.push(node(++k,1));
                child_l[u.id]=k;
                q.push(node(++k,1));
                child_r[u.id]=k;
                b-=2;
            }
        }
        cout<<"Yes"<<endl;
        for(int i=1;i<=k;i++)
            cout<<child_l[i]<<" "<<child_r[i]<<endl;
    }
    return 0;
}