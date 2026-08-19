#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool find_1=false;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(s[i]=='D'&&s[j]=='F'&&s[k]=='S')
                    find_1=true;
    bool find_2=false;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(s[i]=='d'&&s[j]=='f'&&s[k]=='s')
                    find_2=true;
    cout<<find_1<<" "<<find_2<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}