#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
char s[maxn];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int ans=n;
        for(char ch='a';ch<='z';ch++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(s[i]!=ch) cnt++;
            }
            ans=min(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}