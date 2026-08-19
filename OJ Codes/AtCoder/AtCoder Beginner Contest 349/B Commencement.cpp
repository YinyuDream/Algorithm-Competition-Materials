#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];
int cnt[26],tot[N];
int main(){
    cin>>(s+1);
    int n = strlen(s+1);
    for(int i = 1; i <= n; i++){
        cnt[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
        tot[cnt[i]]++;
    for(int i=1;i<=n;i++){
        if(tot[i]!=2&&tot[i]!=0){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}