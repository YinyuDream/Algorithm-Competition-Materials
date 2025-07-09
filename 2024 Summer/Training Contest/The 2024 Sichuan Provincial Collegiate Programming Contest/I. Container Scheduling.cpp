#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll n;
struct node{
    int a,b;
    int x,y;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    ll n,m;
    cin>>n>>m;
    vector<node> v;
    int k=0;
    v.push_back({0,0,0,0});
    while(T--){
        k++;
        ll a,b;
        cin>>a>>b;
        int x=1e9,y=1e9;
        for(int i=0;i<v.size();i++){
            for(int k=0;k<v.size();k++){
                int nowx,nowy;
                int xx,yy;
                nowx=v[i].x+v[i].a;
                nowy=v[k].y+v[k].b;
                xx=nowx+a;
                yy=nowy+b;
                if(xx>n||yy>m)
                    continue;
                int f=0;
                for(int j=0;j<v.size();j++){
                    int minx,miny,maxx,maxy;
                    minx=v[j].x;
                    miny=v[j].y;
                    maxx=v[j].x+v[j].a;
                    maxy=v[j].y+v[j].b;
                    minx=max(nowx,minx);
                    miny=max(nowy,miny);
                    maxx=min(maxx,xx);
                    maxy=min(maxy,yy);
                    if(minx>=maxx||miny>=maxy){
                        f++;
                    }
                }
                if(f==v.size()){
                    if(nowx<x){
                        x=nowx;
                        y=nowy;
                    }
                    if(nowx==x){
                        if(nowy<y){
                            y=nowy;
                        }
                    }
                }
            }
        }
        if(x==1e9&&y==1e9){
            cout<<-1<<'\n';
            continue;
        }
        cout<<x<<' '<<y<<'\n';
        v.push_back({a,b,x,y});
    }
}