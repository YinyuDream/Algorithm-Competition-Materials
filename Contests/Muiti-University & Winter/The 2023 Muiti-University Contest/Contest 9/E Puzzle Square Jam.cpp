#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m,lmn,umn;
int cnt,ans_x[maxn],ans_y[maxn],ans_l[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        lmn=umn=cnt=0;
        cout<<"YES"<<endl;
        while(lmn<n&&umn<m){
            int len=min(n-lmn,m-umn);
            cnt++;
            ans_x[cnt]=lmn;
            ans_y[cnt]=umn;
            ans_l[cnt]=len;
            if(n-lmn==m-umn){
                lmn=n;
                umn=m;
            }else if(n-lmn>m-umn){
                lmn+=len;
            }else{
                umn+=len;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
            cout<<ans_x[i]<<" "<<ans_y[i]<<" "<<ans_l[i]<<endl;
    }
    return 0;
}