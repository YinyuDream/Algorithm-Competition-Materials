#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,mn,mx;
int a[maxn],negative[maxn],positive[maxn],ans[maxn],tot1,tot2,top1,top2,sum,rev;
ll abs_sum;
int main(){
    cin>>T;
    while(T--){
        tot1=tot2=top1=top2=sum=rev=0;
        cin>>n;
        mn=1e9,mx=-1e9;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        abs_sum=0;
        for(int i=1;i<=n;i++)
            abs_sum+=abs(a[i]);
        if(abs_sum==0){
            cout<<"NO"<<endl;
            continue;
        }
        sort(a+1,a+n+1,[&](int x,int y){return abs(x)>abs(y);});
        if(a[1]<0){
            rev=1;
            for(int i=1;i<=n;i++)
                a[i]=-a[i];
        }
        for(int i=1;i<=n;i++)
            mn=min(mn,a[i]),mx=max(mx,a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]>=0) positive[++tot1]=a[i];
            else negative[++tot2]=a[i];
        }
        sum=ans[1]=a[1],top1=1;
        bool up=1;//1:加负的 0:加正的
        for(int i=2;i<=n;i++){
            if(up==1){
                if(negative[top2+1]+sum>mn&&top2+1<=tot2){
                    sum+=negative[top2+1];
                    ans[i]=negative[top2+1];
                    top2++;
                }else{
                    up^=1;
                    sum+=positive[top1+1];
                    ans[i]=positive[top1+1];
                    top1++;
                }
            }else{
                if(positive[top1+1]+sum<mx&&top1+1<=tot1){
                    sum+=positive[top1+1];
                    ans[i]=positive[top1+1];
                    top1++;
                }else{
                    up^=1;
                    sum+=negative[top2+1];
                    ans[i]=negative[top2+1];
                    top2++;
                }
            }
            
        }
        if(rev){
            for(int i=1;i<=n;i++)
                ans[i]=-ans[i];
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}