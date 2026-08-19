#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
struct node{
    long long a,b,c;
}t[maxn];
bool cmpa(node u,node v)
{
    return u.a-u.b-u.c>v.a-v.b-v.c;
}
bool cmpb(node u,node v)
{
    return u.b-u.a-u.c>v.b-v.a-v.c;
}
bool cmpc(node u,node v)
{
    return u.c-u.b-u.a>v.c-v.b-v.a;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i].a;
    for(int i=1;i<=n;i++)
        cin>>t[i].b;
    for(int i=1;i<=n;i++)
        cin>>t[i].c;
    long long sum=0;
    int ans=0;
    sort(t+1,t+n+1,cmpa);
    for(int i=1;i<=n;i++){
        sum+=t[i].a-t[i].b-t[i].c;
        if(sum<=0){
            ans=max(ans,i-1);
            break;
        }
        if(n==i){
            ans=n;
        }
    }
    sum=0;
    sort(t+1,t+n+1,cmpb);
    for(int i=1;i<=n;i++){
        sum+=t[i].b-t[i].a-t[i].c;
        if(sum<=0){
            ans=max(ans,i-1);
            break;
        }
        if(n==i){
            ans=n;
        }
    }
    sum=0;
    sort(t+1,t+n+1,cmpc);
    for(int i=1;i<=n;i++){
        sum+=t[i].c-t[i].b-t[i].a;
        if(sum<=0){
            ans=max(ans,i-1);
            break;
        }
        if(n==i){
            ans=n;
        }
    }
    cout<<(ans?ans:-1);
    return 0;
}