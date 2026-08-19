#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,cnt,pos_b,pos_a;
int a[maxn],b[maxn],prime[maxn],not_prime[maxn],book[maxn];
void find_prime(int x)
{
    for(int i=2;i<=x;i++){
		if(!not_prime[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=x;j++){
			not_prime[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
    cin>>n;
    find_prime(n*2);
    pos_b=cnt+1;
    while(prime[pos_b-1]>=n+1){
        pos_b--;
    }
    
    pos_a=n;
    while(pos_a>0){
        while(true){
            int fill=prime[pos_b]-pos_a;
            b[pos_a]=fill;
            pos_a--;
            book[fill]=1;
            if(fill==n||book[fill+1]==1){
                break;
            }
        }
        while(prime[pos_b-1]>=pos_a+1){
            pos_b--;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    return 0;
}