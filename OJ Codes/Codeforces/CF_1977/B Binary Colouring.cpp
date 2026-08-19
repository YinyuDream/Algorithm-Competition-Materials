#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,x;
void work(int x)
{
    int num[32],ans[32];
    memset(num,0,sizeof(num));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<=31;i++){
        if(x&(1<<i)){
            num[i]=1;
        }
    }
    int top=0;
    while(top<=31){
        if(num[top]==1){
            if(num[top+1]==0){
                ans[top]=1;
                top++;
            }else{
                ans[top]=-1;
                while(num[top]==1){
                    top++;
                }
                num[top]=1;
            }
        }else{
            top++;
        }
    }
    cout<<32<<endl;
    for(int i=0;i<32;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>T;
    while(T--){
        cin>>x;
        work(x);
    }
    return 0;
}