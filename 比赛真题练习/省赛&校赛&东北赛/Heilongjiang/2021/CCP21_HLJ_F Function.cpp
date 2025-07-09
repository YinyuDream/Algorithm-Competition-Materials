#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+10;
int n,cnt;
int f[maxn],not_prime[maxn],prime[maxn];
ll sum;
int main(){
    cin>>n;
    f[1]=1;
    for(int i=2;i<=n;i++){
        if(!not_prime[i]){
            prime[++cnt]=i;
            f[i]=1;
        }
        for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]!=0){
                f[i*prime[j]]=i;
            }else{
                int num=i*prime[j],fac=0;
                while(num%prime[j]==0){
                    num/=prime[j];
                    fac++;
                }
                fac/=2;
                f[i*prime[j]]=1;
                for(int k=1;k<=fac;k++)
                    f[i*prime[j]]*=prime[j];
                f[i*prime[j]]*=num;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
        sum+=f[i];
    cout<<sum;
    return 0;
}