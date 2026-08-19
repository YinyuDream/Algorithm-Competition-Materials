#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int cnt[21];
bool check(int k)
{
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=k;i++){
        for(int j=0;j<=20;j++){
            if(a[i]&(1<<j))cnt[j]++;
        }
    }
    int num=0;
    for(int j=0;j<=20;j++){
        if(cnt[j]>0)
            num+=(1<<j);
    }
    for(int i=k+1;i<=n;i++){
        for(int j=0;j<=20;j++){
            if(a[i]&(1<<j)){
                cnt[j]++;
            }
        }
        for(int j=0;j<20;j++){
            if(a[i-k]&(1<<j)){
                cnt[j]--;
            }
        }
        int num2=0;
        for(int j=0;j<=20;j++){
            if(cnt[j]>0)
                num2+=(1<<j);
        }
        if(num!=num2)return false;
        
    }
    return true;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}