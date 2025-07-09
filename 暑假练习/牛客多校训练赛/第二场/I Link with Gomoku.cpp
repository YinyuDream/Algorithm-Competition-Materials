#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int T,x,y,cnt;
int s[maxn][maxn];
int main(){
    cin>>T;
    while(T--){
        cnt=0;
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(((j-1)/2)%2==0&&i%2==0){
                    s[i][j]=0;
                }else if(((j-1)/2)%2==1&&i%2==1){
                    s[i][j]=0;
                }else if(((j-1)/2)%2==1&&i%2==0){
                    s[i][j]=1;
                }else if(((j-1)/2)%2==0&&i%2==1){
                    s[i][j]=1;
                }
                cnt+=s[i][j];
            }
        }
        if((x*y)%2==0&&cnt!=x*y/2)
            s[x][y]^=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s[i][j]==0){
                    cout<<'o';
                }else{
                    cout<<'x';
                } 
            }
            cout<<endl;
        }
    }
    return 0;
}