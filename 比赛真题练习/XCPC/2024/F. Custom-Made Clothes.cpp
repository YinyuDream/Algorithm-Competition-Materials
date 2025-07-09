#include<bits/stdc++.h>
using namespace std;
int n,k;
bool query(int i,int j,int a)
{
    cout<<"? "<<i<<" "<<j<<" "<<a<<endl;
    fflush(stdout);
    int x;
    cin>>x;
    return x;
}
bool check(int val)
{
    int row=0,ans=0;
    for(int i=n;i;i--){
        while(row<=n-1&&query(row+1,i,val))row++;
        ans+=row;
    }
    return ans>=k;
}
int main(){
    cin>>n>>k;
    k=n*n-k+1;
    int l=1,r=n*n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<"! "<<l;
    fflush(stdout);
    return 0;
}