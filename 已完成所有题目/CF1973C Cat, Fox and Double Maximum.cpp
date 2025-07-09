#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int pos_1[maxn],pos_2[maxn];
bool cmp(int u,int v){
    return a[u]>a[v];
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i+=2)
            pos_1[i/2+1]=i;
        for(int i=2;i<=n;i+=2)
            pos_2[i/2]=i;
        sort(pos_1+1,pos_1+n/2+1,cmp);
        sort(pos_2+1,pos_2+n/2+1,cmp);
        for(int i=1;i<=n/2;i++){
            if(a[pos_1[i]]==1){
                for(int j=1;j<=n/2;j++){
                    swap(pos_1[j],pos_2[j]);
                }
                break;
            }
        }
        for(int i=1;i<=n/2;i++){
            b[pos_1[i]]=n/2+i;
            b[pos_2[i]]=i;
        }
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }   
    return 0;
}