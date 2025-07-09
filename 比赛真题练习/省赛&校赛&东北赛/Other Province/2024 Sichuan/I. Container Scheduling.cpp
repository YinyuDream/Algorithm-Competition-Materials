#include<bits/stdc++.h>
using namespace std;
int n,l,h;
int book[51],minx[51],miny[51],maxx[51],maxy[51];
struct node{
    int lx,ly,rx,ry;
};
bool is_intersect(int lx1,int ly1,int rx1,int ry1,int lx2,int ly2,int rx2,int ry2){
    int x1=max(lx1,lx2),y1=max(ly1,ly2);
    int x2=min(rx1,rx2),y2=min(ry1,ry2);
    return x1<x2&&y1<y2;
}
void work(int eth,int lenx,int leny){
    for(int i=0;i<eth;i++){
        if(book[i]==0)
            continue;
        for(int j=0;j<eth;j++){
            if(book[j]==0)
                continue;
            int lx=maxx[i],ly=maxy[j];
            int rx=lx+lenx,ry=ly+leny;
            if(rx>l||ry>h)
                continue;
            bool flag=true;
            for(int k=1;k<eth;k++){
                if(book[k]==0)
                    continue;
                if(is_intersect(lx,ly,rx,ry,minx[k],miny[k],maxx[k],maxy[k]))
                    flag=false;
            }
            if(flag==false)
                continue;
            if(!book[eth]){
                book[eth]=1;
                minx[eth]=lx;
                miny[eth]=ly;
                maxx[eth]=rx;
                maxy[eth]=ry;
            }else{
                if(minx[eth]>lx){
                    minx[eth]=lx;
                    miny[eth]=ly;
                    maxx[eth]=rx;
                    maxy[eth]=ry;
                }else if(minx[eth]==lx){
                    if(miny[eth]>ly){
                        minx[eth]=lx;
                        miny[eth]=ly;
                        maxx[eth]=rx;
                        maxy[eth]=ry;
                    }
                }
            }
        }
    }
}
int main(){
    book[0]=1;
    cin>>n>>l>>h;
    for(int i=1;i<=n;i++){
        int lenx,leny;
        cin>>lenx>>leny;
        work(i,lenx,leny);
        if(!book[i]){
            cout<<-1<<endl;
        }else{
            cout<<minx[i]<<" "<<miny[i]<<endl;
        }
    }
}