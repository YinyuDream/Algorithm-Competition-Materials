#include<bits/stdc++.h>
using namespace std;
int T,n,sum;
int a[]={0,7,27,41,49,63,78,108};
int main(){
    cin>>T;
    while(T--){
        sum=0;
        cin>>n;
        for(int i=1,num;i<=n;i++){
            cin>>num;
            sum+=a[num];
        }
        if(sum>=120)cout<<sum-50;
        else if(sum>=89)cout<<sum-30;
        else if(sum>=69)cout<<sum-15;
        else cout<<sum;
        cout<<endl;
    }
    return 0;
}