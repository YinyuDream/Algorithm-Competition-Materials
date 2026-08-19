#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int q,cnt;
int prime[maxn],not_prime[maxn],sum[maxn];
int main(){
    scanf("%d",&q);
    for(int i=2;i<maxn;i++){
        if(!not_prime[i])
            prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
    not_prime[0]=not_prime[1]=1;
    sum[0]=1;
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+(not_prime[i]==0);
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}