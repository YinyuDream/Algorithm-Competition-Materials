#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int T,n;
int a[maxn],ans_l[maxn],ans_r[maxn],cnt;
bool check(){
    for(int i=1;i<=n;i++)
        if(a[i]!=i)
            return false;
    return true;
}
pair<int,int> find(){
    for(int len=n;len;len--)
        for(int i=1;i+len-1<=n;i++)
            if(a[i]>a[i+len-1])
                return make_pair(i,i+len-1);
}
int main(){
    cin>>T;
    while(T--){
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        while(!check()){
            auto p=find();
            sort(a+p.first,a+p.second+1);
            ans_l[++cnt]=p.first;
            ans_r[cnt]=p.second;
        }
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
            cout<<ans_l[i]<<" "<<ans_r[i]<<endl;
    }
    return 0;
}