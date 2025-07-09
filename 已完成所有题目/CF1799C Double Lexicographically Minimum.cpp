#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,cnt[26],num[26];
char s[maxn],ans[maxn],rev[maxn];
void work(int tot_num){
    int pos=0,now=0;
    for(int i=1;i<=tot_num;i++){
        for(int j=1;j;j++){
            if(cnt[num[i]]>=2){
                pos++;
                ans[pos]=num[i]+'a';
                ans[n+1-pos]=num[i]+'a';
                cnt[num[i]]-=2;
            }else if(cnt[num[i]]==1){
                now=i;
                goto flag;
            }else break;
        }
    }
    flag:;
    int los=tot_num-now+1;
    if(now==0)return ;
    if(los==1){
        for(int i=pos+1;i<=n;i++){
            if(ans[i])break;
            ans[i]=num[now]+'a';
        }
    }else if(los==2){
        for(int i=pos+1;i<=n;i++){
            if(ans[i])break;
            ans[i]=num[now+1]+'a';
        }
        ans[n/2+1]=num[now]+'a';
    }else{
        pos++;
        ans[n-pos+1]=num[now]+'a';
        ans[pos]=num[now+1]+'a';
        cnt[num[++now]]--;
        pos++;
        for(int i=pos;i<=n;i++){
            if(ans[i])break;
            while(!cnt[num[now]])now++;;
            ans[i]=num[now]+'a';
            cnt[num[now]]--;
        }
    }
}
int main(){
    cin>>T;
    while(T--){
        cin>>(s+1);
        n=strlen(s+1);
        memset(cnt,0,sizeof(cnt));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n+1;i++)
            ans[i]=rev[i]=0;
        int top=0;
        for(int i=1;i<=n;i++)
            cnt[s[i]-'a']++;
        for(int i=0;i<=25;i++)
            if(cnt[i])
                num[++top]=i;
        if(top==1){
            cout<<(s+1)<<endl;
            continue;
        }else{
            work(top);
        }
        for(int i=1;i<=n;i++)
            rev[i]=ans[n-i+1];
        rev[n+1]=ans[n+1]=0;
        if(strcmp(ans+1,rev+1)>0) cout<<ans+1<<endl;
        else cout<<rev+1<<endl;
    }
    return 0;
}