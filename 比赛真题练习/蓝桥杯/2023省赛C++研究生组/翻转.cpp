#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s1[maxn],s2[maxn];
void work()
{
    cin>>(s1+1)>>(s2+1);
    int n=strlen(s1+1);
    for(int i=1;i<=n;i++)
        swap(s1[i],s2[i]);
    if(s1[1]!=s2[1]||s1[n]!=s2[n]){
        cout<<-1<<endl;
        return ;
    }
    int ans=0;
    for(int i=2;i<n;i++){
        if(s1[i]!=s2[i]){
            if(s1[i-1]==s1[i+1]&&s1[i-1]==s2[i])
                s1[i]=s2[i],ans++;
        }
    }
    for(int i=1;i<=n;i++){
        if(s1[i]!=s2[i]){
            cout<<-1<<endl;
            return ;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}