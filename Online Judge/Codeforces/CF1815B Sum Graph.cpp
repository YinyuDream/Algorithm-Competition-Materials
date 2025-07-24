#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int dis_1[maxn],dis_2[maxn],ans[maxn],num[maxn];
struct node{
    int pos,id;
}a[maxn];
bool cmp(node a,node b){
    return a.pos<b.pos;
}
int main(){
    cin>>T;
    while(T--){
        int to_read;
        cin>>n;
        if(n==2){
            cout<<"! 1 2 2 1"<<endl;
            fflush(stdout);
            cin>>to_read;
            continue;
        }
        cout<<"+ "<<n+1<<endl;
        fflush(stdout);
        cin>>to_read;
        cout<<"+ "<<n+2<<endl;
        fflush(stdout);
        cin>>to_read;
        for(int i=2;i<=n;i++){
            cout<<"? "<<1<<" "<<i<<endl;
            fflush(stdout);
            int d;
            cin>>d;
            dis_1[i]=d;
        }
        for(int i=2;i<=n;i++){
            cout<<"? "<<i-1<<" "<<i<<endl;
            fflush(stdout);
            int d;
            cin>>d;
            dis_2[i]=d;
        }
        if(dis_1[2]+dis_1[3]==dis_2[3]){
            a[1]={0,1};
            a[2]={dis_1[2],2};
            a[3]={-dis_1[3],3};
        }else{
            a[1]={0,1};
            a[2]={dis_1[2],2};
            a[3]={dis_1[3],3};
        }
        for(int i=4;i<=n;i++){
            if(dis_1[i-1]+dis_1[i]==dis_2[i]){
                if(a[i-1].pos<0){
                    a[i]={dis_1[i],i};
                }else{
                    a[i]={-dis_1[i],i};
                }
            }else{
                if(a[i-1].pos<0){
                    a[i]={-dis_1[i],i};
                }else{
                    a[i]={dis_1[i],i};
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i+=2)
            num[i]=i/2+1;
        for(int i=2;i<=n;i+=2)
            num[i]=n-i/2+1;
        for(int i=1;i<=n;i++)
            ans[a[i].id]=num[i];
        cout<<"! ";
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        reverse(num+1,num+n+1);
        for(int i=1;i<=n;i++)
            ans[a[i].id]=num[i];
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        fflush(stdout);
        cin>>to_read;
    }
    return 0;
}