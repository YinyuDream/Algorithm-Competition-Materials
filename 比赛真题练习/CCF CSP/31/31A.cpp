#include<bits/stdc++.h>
using namespace std;
int dx,dy,n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int _dx,_dy;
        cin>>_dx>>_dy;
        dx+=_dx;
        dy+=_dy;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        cout<<dx+x<<" "<<dy+y<<endl;
    }
    return 0;
}