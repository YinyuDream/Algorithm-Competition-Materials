#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,k,l,d,ans[maxn];
struct node{
    int id,num;
}row[maxn],column[maxn];
bool cmp(node a,node b)
{
    return a.num>b.num;
}
int main(){
    cin>>n>>m>>k>>l>>d;
    for(int i=1;i<n;i++)
        row[i].id=i;
    for(int i=1;i<m;i++)
        column[i].id=i;
    for(int i=1,x_1,x_2,y_1,y_2;i<=d;i++){
        cin>>x_1>>y_1>>x_2>>y_2;
        if(x_1==x_2){
            if(y_1>y_2){
                swap(y_1,y_2);
            }
            column[y_1].num++;
        }else if(y_1==y_2){
            if(x_1>x_2){
                swap(x_1,x_2);
            }
            row[x_1].num++;
        }
    }
    sort(row+1,row+n,cmp);
    sort(column+1,column+m,cmp);
    
    for(int i=1;i<=k;i++)
        ans[i]=row[i].id;
    sort(ans+1,ans+k+1);
    for(int i=1;i<=k;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    for(int i=1;i<=l;i++)
        ans[i]=column[i].id;
    sort(ans+1,ans+l+1);
    for(int i=1;i<=l;i++)
        cout<<ans[i]<<" ";
    return 0;
}