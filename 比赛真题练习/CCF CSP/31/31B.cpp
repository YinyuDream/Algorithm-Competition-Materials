#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m;
double db[maxn],an[maxn];
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        db[i]=1.0;
    for(int i=1;i<=n;i++){
        int opt;
        double val;
        cin>>opt>>val;
        if(opt==1){
            db[i]=val;
        }else{
            an[i]=val;
        }
    }
    for(int i=2;i<=n;i++)
        db[i]*=db[i-1];
    for(int i=2;i<=n;i++)
        an[i]+=an[i-1];
    for(int i=1;i<=m;i++){
        double x,y;
        int l,r;
        cin>>l>>r>>x>>y;
        double DB=db[r]/db[l-1],AN=an[r]-an[l-1];
        double nx=DB*(x*cos(AN)-y*sin(AN)),ny=DB*(x*sin(AN)+y*cos(AN));
        printf("%.3lf %.3lf\n",nx,ny);
    }
    return 0;
}