#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
int T,mx_len,min_ans;
int l[maxn],r[maxn],num[maxn],f[maxn];
ll n,m;
void work(ll x,int *a){
    int len=0;
    while(x){
        a[++len]=x%10;
        x/=10;
    }
    a[0]=len;
}
void solve(int pos,int mn,int mx,int op)//op=1,上边界，op=2,下边界，op=3,双边界
{
    if(pos==mx_len+1){
        if(min_ans>mx-mn){
            min_ans=mx-mn;
            for(int i=1;i<=mx_len;i++)
                f[i]=num[i];
        }
        return ;
    }
    int ans=10;
    if(op==1){
        for(int i=0;i<r[pos];i++){
            ans=min(ans,max(mx,i)-min(mn,i));
            if(ans<min_ans){
                for(int j=pos;j<=mx_len;j++)
                    num[j]=i;
                for(int i=1;i<=mx_len;i++)
                    f[i]=num[i];
                min_ans=ans;
            }
        }
        num[pos]=r[pos];
        solve(pos+1,min(mn,r[pos]),max(mx,r[pos]),1);
    }else if(op==2){
        for(int i=9;i>l[pos];i--){
            ans=min(ans,max(mx,i)-min(mn,i));
            if(ans<min_ans){
                for(int j=pos;j<=mx_len;j++)
                    num[j]=i;
                for(int i=1;i<=mx_len;i++)
                    f[i]=num[i];
                min_ans=ans;
            }
        }
        num[pos]=l[pos];
        solve(pos+1,min(mn,l[pos]),max(mx,l[pos]),2);
    }else{
        for(int i=l[pos]+1;i<r[pos];i++){
            ans=min(ans,max(mx,i)-min(mn,i));
            if(ans<min_ans){
                for(int j=pos;j<=mx_len;j++)
                    num[j]=i;
                for(int i=1;i<=mx_len;i++)
                    f[i]=num[i];
                min_ans=ans;
            }
        }
        if(r[pos]==l[pos]){
            num[pos]=l[pos];
            solve(pos+1,min(mn,l[pos]),max(mx,l[pos]),3);
        }else{
            num[pos]=l[pos];
            solve(pos+1,min(mn,l[pos]),max(mx,l[pos]),2);
            num[pos]=r[pos];
            solve(pos+1,min(mn,r[pos]),max(mx,r[pos]),1);
        }
    }
}
int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<maxn;i++)
            l[i]=r[i]=num[i]=f[i]=0;
        cin>>n>>m;
        work(n,l);
        work(m,r);
        mx_len=max(l[0],r[0]);
        if(mx_len==1){
            cout<<n<<endl;
            continue;
        }
        if(r[0]>l[0]){
            for(int i=1;i<=l[0];i++)
                cout<<9;
            cout<<endl;
            continue;
        }
        reverse(l+1,l+mx_len+1);
        reverse(r+1,r+mx_len+1);
        min_ans=10;
        if(r[1]-l[1]>1){
            for(int i=1;i<=mx_len;i++)
                cout<<l[1]+1;
        }else if(r[1]==l[1]){
            num[1]=l[1];
            solve(2,l[1],r[1],3);
            for(int i=1;i<=mx_len;i++)
                cout<<f[i];
        }else{
            num[1]=l[1];
            solve(2,l[1],l[1],2);
            num[1]=r[1];
            solve(2,r[1],r[1],1);
            int pos=1;
            while(f[pos]==0)
                pos++;
            for(int i=pos;i<=mx_len;i++)
                cout<<f[i];
        }
        cout<<endl;
    }
    return 0;
}