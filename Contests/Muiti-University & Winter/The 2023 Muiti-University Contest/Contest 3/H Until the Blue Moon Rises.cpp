#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n;
long long sum,a[maxn];
bool check(long long x)
{
    if(x==1)return false;
    long long up=sqrt(x);
    for(long long i=2;i<=up;i++)
        if(x%i==0)
            return false;
    return true;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    if(n==1){
        if(check(a[1]))cout<<"Yes";
        else cout<<"No";
        return 0;
    }
    if(n==2){
        if(sum%2==0){
            if(sum>=4)cout<<"Yes";
            else cout<<"No";
        }else{
            if(sum>=5&&check(sum-2))cout<<"Yes";
            else cout<<"No";
        }
        return 0;
    }
    if(sum%2==0){
        if(sum<2*n)cout<<"No";
        else cout<<"Yes";
    }else{
        if(sum<2*n+1)cout<<"No";
        else cout<<"Yes";
    }
    return 0;
}