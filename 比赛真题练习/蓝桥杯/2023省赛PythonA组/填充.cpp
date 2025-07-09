#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt;
int a[maxn];
char s[maxn];
int main(){
    cin>>s+1;
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='0'||s[i]=='1'){
            for(int j=i-1;j;j--)
                s[j]=s[i];
            break;
        }
    }
    for(int i=n;i;i--){
        if(s[i]=='0'||s[i]=='1'){
            for(int j=i+1;j<=n;j++)
                s[j]=s[i];
            break;
        }
    }
    for(int i=7;i<=n;i++){
        if(s[i]=='?'){
            for(int j=i+1;j<=n;j++){
                if(s[j]!='?'){
                    if(s[i-1]==s[j]){
                        for(int k=i;k<j;k++){
                            s[k]=s[i-1];
                        }
                    }
                    i=j-1;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0';
    int lst=1;
    for(int i=2;i<=n;i++){
        if(a[i]==15){
            if((i-lst)%2==1){
                a[i]=a[i-1];
            }else{
                a[i]=a[i-1]^1;
                for(int j=i+1;j<=n;j++){
                    if(a[j]!=15)
                        break;
                    a[j]=a[i];
                }
            }
        }
        if(a[i]!=a[i-1]){
            lst=i;
        }
    }
    lst=1;
    a[n+1]=-1;
    for(int i=2;i<=n+1;i++)
        if(a[i]!=a[i-1])
            cnt+=(i-lst)/2,lst=i;
    cout<<cnt<<endl;
    return 0;
}