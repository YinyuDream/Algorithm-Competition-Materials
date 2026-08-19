#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k;
int a[maxn];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[n-1]<=a[n]&&a[n]>=k){
        cout<<"Python will never be faster than C++";
        return 0;
    }
    for(int i=n+1;i;i++){
        a[i]=max(0,2*a[i-1]-a[i-2]);
        if(a[i]<k){
            printf("Python 3.%d will be faster than C++",i);
            return 0;
        }
    }
    return 0;
}