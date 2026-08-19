#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int now=1,cnt_1=0,cnt_2=0;
    for(int i=1;i<=n;i++){
        while(now<n&&b[now]<a[i]){
            now++;
        }
        if(now<=n&&b[now]>a[i]){
            cnt_1++;
            now++;
        }
    }
    now=n;
    for(int i=n;i>=1;i--){
        while(now>1&&b[now]>a[i]){
            now--;
        }
        if(now>=1&&b[now]<a[i]){
            cnt_2++;
            now--;
        }
    }
    cout<<cnt_2-(n-cnt_1)+1<<endl;
    for(int i=n-cnt_1;i<=cnt_2;i++){
        cout<<i<<" ";
    }
}
int main(){
    solve();
}