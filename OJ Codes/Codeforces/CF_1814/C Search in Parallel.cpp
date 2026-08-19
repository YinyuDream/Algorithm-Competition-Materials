#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,s1,s2;
int ans1[maxn],ans2[maxn];
struct node{
    int cnt,id;
}r[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>s1>>s2;
        for(int i=1;i<=n;i++)
            cin>>r[i].cnt,r[i].id=i;
        sort(r+1,r+n+1,[](node a,node b){return a.cnt>b.cnt;});
        int a=0,b=0;
        while(a+b<n){
            if((a+1)*s1<=(b+1)*s2){
                a++;
                ans1[a]=r[a+b].id;
            }else{
                b++;
                ans2[b]=r[a+b].id;
            }
        }
        cout<<a<<" ";
        for(int i=1;i<=a;i++)
            cout<<ans1[i]<<" ";
        cout<<endl;
        cout<<b<<" ";
        for(int i=1;i<=b;i++)
            cout<<ans2[i]<<" ";
        cout<<endl;
    }
    return 0;
}