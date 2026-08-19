#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int cnt=0;
int a[N],not_prime[N],prime[N];
void init(){
    for(int i=2;i<N;i++){
        if(!not_prime[i]){
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&&i*prime[j]<N;j++){
            not_prime[prime[j]*i]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
int main(){
    init();
    for(int i=1;i<=cnt;i++){
        long long now=prime[i];
        while(now<N){
            a[now]=1;
            now=now*prime[i];
        }
    }
    a[1]=1;
    for(int i=1;i<N;i++)
        a[i]^=1;
    for(int i=1;i<N;i++)
        a[i]+=a[i-1];
    int x;
    cin>>x;
    cout<<a[x];
}