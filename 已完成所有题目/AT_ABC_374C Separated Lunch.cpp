#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=2e9;
    for(int i=0;i<(1<<n);i++){
        int sum_1=0,sum_2=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                sum_1+=a[j];
            }else{
                sum_2+=a[j];
            }
        }
        ans=min(ans,max(sum_1,sum_2));
    }
    cout<<ans<<endl;
    return 0;
}