#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt;
int not_prime[maxn],prime[maxn];
void init(){
    for(int i=2;i<maxn;i++){
        if(!not_prime[i])
            prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int work(int num)
{
    int ans=1e9;
    if(!not_prime[num])
        return num;
    for(int i=1;i<=cnt;i++)
        if(num%prime[i]==0)
            ans=min(ans,num-prime[i]+1);
    return ans;
}
int main(){
    init();
    cin>>n;
    if(!not_prime[n]){
      cout<<-1;
      return 0;
    }
    int ans=1e9;
    for(int i=1;i<=cnt;i++){
        if(n%prime[i]==0){
            for(int j=n-prime[i]+1;j<=n;j++){
                ans=min(ans,work(j));
            }
        }
    }
    cout<<(ans==1e9?-1:ans);
    return 0;
}