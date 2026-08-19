#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
int n,cnt;
struct node{
    int t,pri;
    node(int _t,int _pri){
        t=_t;
        pri=_pri;
    }
    friend bool operator <(node a,node b)
    {
        if(a.pri!=b.pri)return a.pri<b.pri;
        else return a.t>b.t;
    }
};
priority_queue<node>q[4];
void work()
{
    cnt=0;
    for(int i=1;i<=3;i++)
        q[i].empty();
     for(int i=1,a,b;i<=n;i++){
        string s;
        cin>>s;
        if(s=="IN"){
            cin>>a>>b;
            q[a].push(node(++cnt,b));
        }else{
            cin>>a;
            if(q[a].size()){
                cout<<q[a].top().t<<endl;
                q[a].pop();
            }else{
                cout<<"EMPTY"<<endl;
            }
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF)
        work();
    return 0;
}