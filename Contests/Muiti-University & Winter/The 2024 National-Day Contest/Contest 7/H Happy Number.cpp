#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    for(long long i=1,now=3;i<=30;i++,now*=3){
        long long k=n-(now-1)/2;
        if(k<0){
            break;
        }
        vector<long long> num;
        while(k){
            num.push_back(k%3);
            k/=3;
        }
        while(num.size()<i){
            num.push_back(0);
        }
        if(num.size()==i){
            reverse(num.begin(),num.end());
            vector<long long> ord;
            ord.push_back(2);
            ord.push_back(3);
            ord.push_back(6);
            for(auto x:num){
                cout<<ord[x];
            }
            break;
        }
    }
    return 0;
}