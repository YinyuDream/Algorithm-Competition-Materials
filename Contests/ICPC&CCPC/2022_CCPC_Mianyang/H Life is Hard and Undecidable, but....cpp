#include<bits/stdc++.h>
using namespace std;
const int maxn=110,maxk=310;
int n;
int mapp[maxn][maxk][maxk],ans_x[maxn],ans_y[maxn];
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
bool check(int k)
{
    for(int i=1;i<=maxk;i++)
        for(int j=1;j<=maxk;j++)
            if(mapp[k][i][j]==1)return false;
    return true;
}
int main(){
    cin>>n;
    mapp[0][1+10][3+10]=mapp[0][2+10][4+10]=mapp[0][3+10][2+10]=mapp[0][3+10][3+10]=mapp[0][3+10][4+10]=1;
    mapp[0][29+10][29+10]=mapp[0][29+10][30+10]=mapp[0][30+10][29+10]=mapp[0][30+10][30+10]=1;
    for(int k=1;k<=100;k++){
        for(int i=1;i<maxk;i++){
            for(int j=1;j<maxk;j++){
                int cnt=0;
                for(int l=0;l<8;l++){
                    int x=i+dx[l],y=j+dy[l];
                    cnt+=mapp[k-1][x][y];
                }
                if(cnt==3)mapp[k][i][j]=1;
                if(cnt==2&&mapp[k-1][i][j])mapp[k][i][j]=1;
            }
        }
    }
    for(int i=1;i<maxk;i++){
        for(int j=1;j<maxk;j++){
            if(mapp[100-n][i][j]==1){
                ans_x[++ans_x[0]]=i;
                ans_y[++ans_y[0]]=j;
            }
        }
    }
    cout<<ans_x[0]<<endl;
    for(int i=1;i<=ans_x[0];i++){
        cout<<ans_x[i]<<" "<<ans_y[i]<<endl;
    }
    return 0;
}