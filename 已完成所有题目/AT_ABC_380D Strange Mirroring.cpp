#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int q;
    cin>>q;
    while(q--){
        long long x;
        cin>>x;
        long long mx=0;
        while(n*(1ll<<mx)<x){
            mx++;
        }
        int val=0;
        while(x>n){
            if(x>n*(1ll<<(mx-1))){
                x-=n*(1ll<<(mx-1));
                val^=1;
            }
            mx--;
        }
        if(val==0){
            cout<<s[x-1]<<endl;
        }else{
            //lowercase->upper, upper->lower
            cout<<(char)(s[x-1]^32)<<" ";
        }
    }
    return 0;
}