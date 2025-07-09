#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> G(n+1,vector<int>(n+1)),H(n+1,vector<int>(n+1));
    int mg,mh;
    cin>>mg;
    for(int i=0;i<mg;i++){
        int a,b;
        cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
    }
    cin>>mh;
    for(int i=0;i<mh;i++){
        int a,b;
        cin>>a>>b;
        H[a][b]=1;
        H[b][a]=1;
    }
    vector<vector<int>> A(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>A[i][j];
            A[j][i]=A[i][j];
        }
    }
    vector<int> P(n+1);
    iota(P.begin(),P.end(),0);
    int ans=INT_MAX;
    do{
        int val=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(G[i][j]+H[P[i]][P[j]]==1){
                    val+=A[P[i]][P[j]];
                }
            }
        }
        ans=min(ans,val);
    }while(next_permutation(P.begin()+1,P.end()));
    cout<<ans<<endl;
}