#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m;
set<string>win;
int sum,num_win[6],num_new[6];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            string s;
            cin>>s;
            win.insert(s);
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string s;
        int pos;
        cin>>s>>pos;
        if(win.find(s)!=win.end())
            sum++,num_win[pos]++;
        else
            num_new[pos]++;
    }
    int mn=m;
    for(int i=1;i<=5;i++)
        mn=min(mn,num_new[i]+num_win[i]);
    cout<<min(mn,sum)<<endl;
    return 0;
}