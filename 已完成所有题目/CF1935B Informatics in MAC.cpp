#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,cnt,top,ans;
int a[maxn],mex_l[maxn],mex_r[maxn];
int num[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0)
                cnt++;
        }
        if(cnt==0){
            cout<<2<<endl<<"1 1"<<endl<<2<<" "<<n<<endl;
            continue;
        }else if(cnt==1){
            cout<<-1<<endl;
            continue;
        }else{
            top=ans=0;
            for(int i=0;i<=n;i++)
                num[i]=0;
            for(int i=1;i<=n;i++){
                num[a[i]]++;
                while(num[top])
                    top++;
                mex_l[i]=top;
            }
            top=0;
            for(int i=0;i<=n;i++)
                num[i]=0;
            for(int i=n;i;i--){
                num[a[i]]++;
                while(num[top])
                    top++;
                mex_r[i]=top;
            }
            for(int i=1;i<n;i++){
                if(mex_l[i]==mex_r[i+1]){
                    ans=i;
                    break;
                }
            }
            if(ans!=0)cout<<2<<endl<<1<<" "<<ans<<endl<<ans+1<<" "<<n<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}