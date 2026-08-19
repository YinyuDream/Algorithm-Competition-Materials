#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,pos,sum[maxn],cnt[20],num_cnt[20];
ll ans,a[maxn];
bool is_4(ll x)
{
    return (x%100)%4==0;
}
int up(ll x)
{
    int sum_p=0;
    while(x!=0){
        sum_p+=x%10;
        x/=10;
    }
    return sum_p;
}
int main(){
    cin>>n;
    pos=n+1;
    for(int i=1;i<=n;i++)
            cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=up(a[i]);
        cnt[sum[i]%9]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=10){
            pos=i;
            break;
        }else{
            num_cnt[a[i]]++;
        }
    }
    for(int i=pos;i<=n;i++){
        if(is_4(a[i])){
            int num=(9-sum[i]%9)%9;
            cnt[sum[i]%9]--;
            ans+=cnt[num];
            cnt[sum[i]%9]++;
        }
    }
    ans+=1ll*num_cnt[3]*num_cnt[6];
    ans+=1ll*num_cnt[2]*num_cnt[7];
    for(int i=1;i<=9;i++){
        for(int j=pos;j<=n;j++){
            if((sum[j]+i)%9==0&&(10*(a[j]%10)+i)%4==0){
                ans+=num_cnt[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}