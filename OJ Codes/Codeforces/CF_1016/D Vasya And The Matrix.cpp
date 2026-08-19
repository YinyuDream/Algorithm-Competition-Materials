#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> ans(n,vector<int>(m));
    vector<int> a(n),b(m);
    int xor_sum_a=0,xor_sum_b=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        xor_sum_a^=a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        xor_sum_b^=b[i];
    }
    if(xor_sum_a!=xor_sum_b){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<=30;i++){
        vector<int> pos_a,pos_b;
        for(int j=0;j<n;j++){
            int val=(a[j]>>i)&1;
            if(val) pos_a.push_back(j);
        }
        for(int j=0;j<m;j++){
            int val=(b[j]>>i)&1;
            if(val) pos_b.push_back(j);
        }
        int sza=pos_a.size(),szb=pos_b.size();
        if(sza%2!=szb%2){
            cout<<"NO"<<endl;
            return 0;
        }
        if(sza&&szb){
            for(int j=0;j<sza-(sza%2==0);j++){
                for(int k=0;k<szb-(szb%2==0);k++){
                    ans[pos_a[j]][pos_b[k]]|=(1<<i);
                }
            }
            if(sza%2==0&&szb%2==0){
                ans[pos_a[sza-1]][pos_b[szb-1]]|=(1<<i);
            }
        }
        if(sza==0&&szb){
            for(int j=0;j<szb;j++){
                ans[0][pos_b[j]]|=(1<<i);
            }
        }
        if(sza&&szb==0){
            for(int j=0;j<sza;j++){
                ans[pos_a[j]][0]|=(1<<i);
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}