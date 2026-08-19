#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans=0x7f7f7f7f,ans_p_b,ans_p_a;
int a[maxn],b[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(a+1,a+n+1,b[i])-a;
        if(pos==1){
            if(ans>abs(a[pos]-b[i])){
                ans=abs(a[pos]-b[i]);
                ans_p_b=i;
                ans_p_a=pos;
            }
        }else if(pos==n+1){
            if(ans>abs(a[n]-b[i])){
                ans=abs(a[n]-b[i]);
                ans_p_b=i;
                ans_p_a=n;
            }
        }else{
            if(ans>abs(a[pos]-b[i])){
                ans=abs(a[pos]-b[i]);
                ans_p_b=i;
                ans_p_a=pos;
            }
            if(ans>abs(a[pos-1]-b[i])){
                ans=abs(a[pos-1]-b[i]);
                ans_p_b=i;
                ans_p_a=pos-1;
            }
        }
    }
    swap(a[ans_p_a],a[ans_p_b]);
    for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
    return 0;
}