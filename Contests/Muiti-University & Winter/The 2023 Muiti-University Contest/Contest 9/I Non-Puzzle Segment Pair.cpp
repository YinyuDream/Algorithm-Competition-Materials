#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10,N=5e5;
const ll p=1e9+7;
int n;
int cnt_a[maxn],cnt_b[maxn],out_a[maxn],out_b[maxn];
ll ans,pow_2[maxn];
struct seg{
    int l,r;
};
int main(){
    pow_2[0]=1;
    for(int i=1;i<=N;i++){
        pow_2[i]=pow_2[i-1]*2%p;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        seg a,b;
        cin>>a.l>>a.r>>b.l>>b.r;
        if(a.l>b.l){
            swap(a,b);
        }
        if(b.l<=a.r){
            if(a.l!=b.l){
                cnt_a[min(a.l,b.l)]++;
                cnt_a[max(a.l,b.l)]--;
                //out_a[max(a.l,b.l)-1]++;
            }
            cnt_b[max(a.l,b.l)]++;
            cnt_b[min(a.r,b.r)+1]--;
            if(a.r!=b.r){
                out_b[min(a.r,b.r)]++;
            }else{
                out_a[a.r]++;
            }
            if(a.r!=b.r){
                cnt_a[min(a.r,b.r)+1]++;
                cnt_a[max(a.r,b.r)+1]--;
                out_a[max(a.r,b.r)]++;
            }
        }else{
            cnt_a[a.l]++;
            cnt_a[a.r+1]--;
            cnt_a[b.l]++;
            cnt_a[b.r+1]--;
            out_a[a.r]++;
            out_a[b.r]++;
        }
    }
     
    for(int i=1;i<=N;i++){
        cnt_a[i]+=cnt_a[i-1];
        cnt_b[i]+=cnt_b[i-1];
    }
    for(int i=1;i<=N;i++){
        if(cnt_a[i]+cnt_b[i]==n&&(out_a[i]||out_b[i])){
            if(out_b[i]!=0&&out_a[i]==0){
                ans+=pow_2[cnt_b[i]-out_b[i]]*(pow_2[out_b[i]]-1)%p;
            }else{
                ans+=pow_2[cnt_b[i]];
            }
            ans%=p;
        }
    }
    cout<<ans<<endl;
    return 0;
}