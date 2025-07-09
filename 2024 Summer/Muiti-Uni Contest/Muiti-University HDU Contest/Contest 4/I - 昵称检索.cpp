#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const int maxm=1e6+10;
vector<string> dates;
int pos_num[10][maxm],pos_letter[26][maxm];
int tot_num[10],tot_letter[26],top_letter[26],top_num[10];
int next_letter[maxm][26],prev_num[maxm][10];
char S[maxm],name[31];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void solve(){
    int n,m;
    n=read();m=read();
    scanf("%s",S);
    memset(tot_num,0,sizeof(tot_num));
    memset(tot_letter,0,sizeof(tot_letter));
    memset(top_letter,0,sizeof(top_letter));
    memset(top_num,0,sizeof(top_num));
    for(int i=0;i<m;i++){
        for(int j=0;j<26;j++)
            next_letter[i][j]=-1;
        for(int j=0;j<=9;j++)
            prev_num[i][j]=-1;
    }
    for(int i=0;i<m;i++){
        if(S[i]>='0'&&S[i]<='9'){
            pos_num[S[i]-'0'][++tot_num[S[i]-'0']]=i;
        }else{
            pos_letter[S[i]-'a'][++tot_letter[S[i]-'a']]=i;
        }
    }
    for(int i=0;i<m;i++){
        if(S[i]>='0'&&S[i]<='9') continue;
        for(int j=0;j<26;j++){
            if(!tot_letter[j]) continue;
            while(top_letter[j]<=tot_letter[j]&&pos_letter[j][top_letter[j]]<=i)
                top_letter[j]++;
            if(top_letter[j]<=tot_letter[j])
                next_letter[i][j]=pos_letter[j][top_letter[j]];
        }
    }
    for(int i=0;i<=9;i++)
        if(tot_num[i])
            top_num[i]=tot_num[i];
    for(int i=m-1;i>=0;i--){
        if(S[i]>='a'&&S[i]<='z') continue;
        for(int j=0;j<=9;j++){
            if(!tot_num[j]) continue;
            while(top_num[j]>0&&pos_num[j][top_num[j]]>=i)
                top_num[j]--;
            if(top_num[j]>0)
                prev_num[i][j]=pos_num[j][top_num[j]];
        }
    }
    vector<int> dp(m+1,0);
    for(auto i:dates){
        if(!tot_num[i[3]-'0']) continue;
        int pos=pos_num[i[3]-'0'][tot_num[i[3]-'0']];
        for(int j=2;j>=0;j--){
            if(prev_num[pos][i[j]-'0']!=-1){
                pos=prev_num[pos][i[j]-'0'];
            }else{
                pos=-1;
                break;
            }
        }
        if(pos!=-1){
            dp[pos]++;
        }
    }
    for(int i=m-2;i>=0;i--){
        dp[i]+=dp[i+1];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        scanf("%s",name);
        if(!tot_letter[name[0]-'a']){
            continue;
        }
        int pos=pos_letter[name[0]-'a'][1],len=strlen(name);
        for(int j=1;j<len;j++){
            if(next_letter[pos][name[j]-'a']!=-1){
                pos=next_letter[pos][name[j]-'a'];
            }else{
                pos=-1;
                break;
            }
        }
        if(pos!=-1){
            ans+=dp[pos];
        }
    }
    print(ans),putchar('\n');
}
int main(){
    vector<int> month={0,31,29,31,30,31,30,31,31,30,31,30,31};
    for(int i=1;i<=12;i++){
        for(int j=1;j<=month[i];j++){
            string day=to_string(j);
            if(day.size()==1) day="0"+day;
            string month=to_string(i);
            if(month.size()==1) month="0"+month;
            dates.push_back(month+day);
        }
    }
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}