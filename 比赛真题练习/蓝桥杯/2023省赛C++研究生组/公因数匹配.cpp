#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn];
vector<int>pos[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                pos[j].push_back(i);
                pos[a[i]/j].push_back(i);
            }
        }
    }
    int ansl=0,ansr=0;
    for(int i=2;i<maxn;i++){
        if(pos[i].size()>=2){
            sort(pos[i].begin(),pos[i].end());
            if(!ansl&&!ansr){
                ansl=pos[i][0];
                ansr=pos[i][1];
            }else if(ansl>pos[i][0]){
                ansl=pos[i][0];
                ansr=pos[i][1];
            }else if(ansr>pos[i][1]){
                ansl=pos[i][0];
                ansr=pos[i][1];
            }
        }
    }
    cout<<ansl<<" "<<ansr<<endl;
    return 0;
}