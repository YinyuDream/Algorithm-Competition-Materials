#include<bits/stdc++.h>
using namespace std;
int conv(string t)
{
    int h=stoi(t.substr(0,2));
    int m=stoi(t.substr(3,2));
    int s=stoi(t.substr(6,2));
    return h*3600+m*60+s;
}
int main(){
    int lim=conv("24:00:01");
    vector<int> a(conv("24:00:00"));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string st,ed;
        cin>>st>>ed;
        int l=conv(st),r=conv(ed);
        a[l]++,a[r+1]--;
    }
    int ans=a[0];
    for(int i=1;i<lim;i++){
        a[i]+=a[i-1];
        ans=max(ans,a[i]);
    }
    cout<<ans<<endl;
}