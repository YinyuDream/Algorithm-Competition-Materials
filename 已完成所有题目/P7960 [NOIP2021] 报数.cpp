#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int cnt,T,num[maxn],flag[maxn];
bool check(int x)
{
    while(x!=0){
        if(x%10==7)return true;
        x/=10;
    }
    return false;
}
int main(){
    for(int i=1;i<maxn;i++)
        if(check(i))
            num[++cnt]=i;
    for(int i=1;i<=cnt;i++){
        if(flag[num[i]])continue;
        for(int j=1;j*num[i]<maxn;j++){
            flag[j*num[i]]=1;
        }
    }
    cnt=0;
    for(int i=1;i<maxn;i++){
        if(!flag[i]){
            num[++cnt]=i;
        }
    }
    cin>>T;
    for(int i=1,n;i<=T;i++){
        cin>>n;
        int pos=lower_bound(num+1,num+cnt+1,n)-num;
        if(num[pos]!=n){
            cout<<-1<<endl;
            continue;
        }
        cout<<num[pos+1]<<endl;
    }
    return 0;
}