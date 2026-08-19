#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,top;
struct node{
    int type;
    int _x1,_y1,_x2,_y2,_r;
    char ch;
}a[maxn];
void work(int _x1,int _y1,int _x2,int _y2)
{
    vector<vector<char>> ans(_y2-_y1+2,vector<char>(_x2-_x1+2,'.'));
    for(int i=1;i<=top;i++){
        for(int y=1;y<=_y2-_y1+1;y++){
            for(int x=1;x<=_x2-_x1+1;x++){
                int nx=x+_x1-1,ny=y+_y1-1;
                if(a[i].type==1){
                    if((1ll*nx-a[i]._x1)*(nx-a[i]._x1)+(1ll*ny-a[i]._y1)*(ny-a[i]._y1)<=1ll*a[i]._r*a[i]._r)
                        ans[y][x]=a[i].ch;
                }else if(a[i].type==2){
                    if(nx>=a[i]._x1&&nx<=a[i]._x2&&ny>=a[i]._y1&&ny<=a[i]._y2)
                        ans[y][x]=a[i].ch;
                }
            }
        }
    }
    for(int j=_y2-_y1+1;j;j--){
        for(int i=1;i<=_x2-_x1+1;i++){
            cout<<ans[j][i];
        }
        cout<<endl;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s=="Circle"){
            int x,y,r;
            char col;
            cin>>x>>y>>r>>col;
            a[++top]={1,x,y,0,0,r,col};
        }else if(s=="Rectangle"){
            int _x1,_y1,_x2,_y2;
            char col;
            cin>>_x1>>_y1>>_x2>>_y2>>col;
            a[++top]={2,_x1,_y1,_x2,_y2,0,col};
        }else{
            int _x1,_y1,_x2,_y2;
            cin>>_x1>>_y1>>_x2>>_y2;
            work(_x1,_y1,_x2,_y2);
        }
    }
    return 0;
}