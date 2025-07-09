#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m,ans;
struct node{
    int pos,num;
}a[maxn];
bool operator <(node u,node v)
{
    return u.pos<v.pos;
}
int main(){
    cin>>T;
    while(T--){
        ans=1;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
            scanf("%d%d",&a[i].pos,&a[i].num);
        sort(a+1,a+m+1);
        for(int i=1;i<m;i++){
            if(a[i].pos==a[i+1].pos&&a[i].num!=a[i+1].num){
                ans=0;
                break;   
            }
        }
        for(int i=1;i<=m;i++){
            if(a[i].num!=0){
                if(a[i-1].num==0&&a[i].num>a[i].pos-a[i-1].pos)
                    ans=0;
                if(a[i].num-a[i-1].num!=a[i].pos-a[i-1].pos&&a[i].num>a[i].pos-a[i-1].pos-1)
                    ans=0;
            }
        }
        cout<<(ans?"Yes":"No")<<endl;
    }
    return 0;
}