#include<bits/stdc++.h>
using namespace std;
#define ll long long 
map<string,int>mm;
string ss[200000];
int main(){
    int n;
    scanf("%d",&n);
    int k;
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            string s;
            cin>>s;
            mm[s]++;
        }
    }
    int ans=0;
    for(auto i=mm.begin();i!=mm.end();i++){
        if((*i).second==n){
            ans++;
            ss[ans]=(*i).first;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        cout<<ss[i]<<endl;
    }
    return 0;
}