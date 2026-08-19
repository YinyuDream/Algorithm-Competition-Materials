#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int n;
int a[maxn];
long long ans;
vector<int>pos[10];
bool cmp(int x,int y){
    return a[x]<a[y];
}
int main(){
    cin>>n;
    for(int i=1,num;i<=n;i++){
        cin>>num;
        pos[num].push_back(i);
        cin>>a[i];
    }
    for(int i=0;i<=9;i++)
        sort(pos[i].begin(),pos[i].end(),cmp);
    for(int i=0;i<=9;i++){
        if(pos[i].size()>n/10){
            for(int j=0;j<pos[i].size()-n/10;j++){
                ans+=a[pos[i][j]];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}