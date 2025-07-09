#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2,T;
int dis[8][8],book[8][8];
int dir[8][5]={
    {0,0,0,0,0},
    {0,2,3,0,0},
    {0,1,4,0,0},
    {0,1,4,0,0},
    {0,2,3,5,6},
    {0,4,7,0,0},
    {0,4,7,0,0},
    {0,5,6,0,0}
};
queue<pair<int,int> >q;
int main(){
    cin>>T;
    while(T--){
        cin>>a1>>a2>>b1>>b2;
        memset(dis,0,sizeof dis);
        memset(book,0,sizeof book);
        if(a1>a2)swap(a1,a2);
        if(b1>b2)swap(b1,b2);
        dis[a1][a2]=0;
        book[a1][a2]=1;
        q.push(make_pair(a1,a2));
        while(q.size()){
            pair<int,int> u=q.front();
            int u1=u.first,u2=u.second;
            q.pop();
            for(int i=1;i<=4;i++){
                int v=dir[u1][i],tu2=u2;
                if(v!=u2&&v>0){
                    if(v>tu2){
                        swap(v,tu2);
                    }
                    if(book[v][tu2]==0){
                        q.push(make_pair(v,tu2));
                        dis[v][tu2]=dis[u1][u2]+1;
                        book[v][tu2]=1;
                    }
                }
            }
            for(int i=1;i<=4;i++){
                int v=dir[u2][i],tu1=u1;
                if(v!=u1&&v>0){
                    if(v>tu1){
                        swap(v,tu1);
                    }
                    if(book[v][tu1]==0){
                        q.push(make_pair(v,tu1));
                        dis[v][tu1]=dis[u1][u2]+1;
                        book[v][tu1]=1;
                    }
                }
            }
        }
        cout<<dis[b1][b2]<<endl;
    }
    return 0;
}