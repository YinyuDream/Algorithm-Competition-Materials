#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int p=1e9+7;
vector<int> pw2(maxn);
int main(){
    pw2[0]=1;
    for(int i=1;i<maxn;i++){
        pw2[i]=pw2[i-1]*2%p;
    }
    int T;
    cin>>T;
    vector<int> n(T),m(T);
    for(int i=0;i<T;i++)
        cin>>n[i];
    for(int i=0;i<T;i++)
        cin>>m[i];
    for(int i=0;i<T;i++){
        if(m[i]>n[i]){
            cout<<0<<endl;
        }else if(m[i]==n[i]){
            cout<<1<<endl;
        }else{
            cout<<pw2[m[i]]<<endl;
        }
    }
    return 0;
}