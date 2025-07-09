#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;
int a[maxn];
long long sum;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    sum%=k;
    int cnt=0;
    sort(a+1,a+n+1);
    for(int i=n;i;i--){
        if(sum==0)break;
        if(sum>=a[i]){
            sum-=a[i];
            cnt++;
        }else{
            sum=0;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}