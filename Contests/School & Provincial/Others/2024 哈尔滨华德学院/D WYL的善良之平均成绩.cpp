#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,sum,cnt;
int a[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(round(1.0*sum/n)==5){
            break;
        }
        sum=sum-a[i]+5;
        cnt++;
    }
    cout<<cnt;
    return 0;
}