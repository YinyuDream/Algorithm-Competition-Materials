#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> nums(n+1);
    auto work=[&](vector<int> &x){
        vector<int> num(n+1);
        int l=0;
        num[x[0]]++;
        while(l+1<x.size()&&num[x[l+1]]==0){
            l++;
            num[x[l]]++;
        }
        int val=0;
        for(int i=0;i<x.size();i++){
            val=max(val,(l-i+1)*2);
            num[x[i]]--;
            while(l+1<x.size()&&num[x[l+1]]==0){
                l++;
                num[x[l]]++;
            }
        }
        return val;
    };
    int cnt=0,ans=0;
    for(int i=1;i<=n;i+=2){
        if(a[i]==a[i+1]){
            nums[cnt].push_back(a[i]);
        }else{
            cnt++;
        }
    }
    for(auto &x:nums){
        if(x.empty()){
            continue;
        }
        ans=max(ans,work(x));
    }
    nums.clear();
    nums.resize(n+1);
    cnt=0;
    for(int i=2;i<=n;i+=2){
        if(a[i]==a[i+1]){
            nums[cnt].push_back(a[i]);
        }else{
            cnt++;
        }
    }
    for(auto &x:nums){
        if(x.empty()){
            continue;
        }
        ans=max(ans,work(x));
    }
    cout<<ans<<endl;
    return 0;
}