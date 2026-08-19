#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,cnt;
ll sum;
int main(){
    cin>>T;
    while(T--){
        sum=0;
        for(int i=1;i<=n;i++){
            int num;
            cin>>num;
            if(num%2==0)
                cnt++;
            while(num%2==0)
              num/=2;
            sum+=num;
        }
        if((sum+cnt)%2==0)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}