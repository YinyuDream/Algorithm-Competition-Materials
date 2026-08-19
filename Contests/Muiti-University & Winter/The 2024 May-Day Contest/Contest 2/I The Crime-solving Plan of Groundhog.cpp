#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn],add[maxn],cnt[10];
int main(){
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof cnt);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        int ans_a=0;
        for(int i=1;i<=9;i++){
            if(cnt[i]!=0){
                ans_a=i;
                cnt[i]--;
                break;
            }
        }
        int top=0;
        for(int i=1;i<=9;i++){
            if(cnt[i]!=0){
                b[++top]=i;
                cnt[i]--;
                break;
            }
        }
        for(int i=0;i<=9;i++){
            while(cnt[i]!=0){
                b[++top]=i;
                cnt[i]--;
            }
        }
        reverse(b+1,b+top+1);
        for(int i=1;i<=top;i++){
            b[i]=(b[i]*ans_a)+add[i];
            add[i+1]=b[i]/10;
            b[i]%=10;
        }
        top++;
        b[top]=add[top];
        if(b[top]==0)
            top--;
        for(int i=top;i;i--)
            cout<<b[i];
        cout<<endl;
    }
    return 0;
}