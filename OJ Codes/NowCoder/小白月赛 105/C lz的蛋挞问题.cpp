#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    array<string,2> s;
    cin>>s[0]>>s[1];
    s[0]="x"+s[0]+"x";
    s[1]="x"+s[1]+"x";
    int ans=0;
    auto check=[&](array<array<char,3>,2> a){
        array<int,6> fa;
        iota(fa.begin(),fa.end(),0);
        int cnt=0;
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                if(a[i][j]=='.'){
                    cnt++;
                }
            }
        }
        auto find=[&](auto &&self,int u)->int{
            return u==fa[u]?u:fa[u]=self(self,fa[u]);
        };
        auto merge=[&](int u,int v){
            int fu=find(find,u),fv=find(find,v);
            if(fu!=fv){
                fa[fu]=fv;
                cnt--;
            }
        };
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                if(a[i][j]=='.'){
                    if(i==0&&a[i+1][j]=='.'){
                        merge(3*i+j,3*(i+1)+j);
                    }
                    if(j<=1&&a[i][j+1]=='.'){
                        merge(3*i+j,3*i+j+1);
                    }
                    if(i==1&&a[i-1][j]=='.'){
                        merge(3*i+j,3*(i-1)+j);
                    }
                    if(j>=1&&a[i][j-1]=='.'){
                        merge(3*i+j,3*i+j-1);
                    }
                }
            }
        }
        return cnt;
    };
    for(int i=1;i<=n;i++){
        if(s[0][i]=='.'){
            array<array<char,3>,2> a;
            a[0][0]=s[0][i-1];
            a[0][1]=s[0][i];
            a[0][2]=s[0][i+1];
            a[1][0]=s[1][i-1];
            a[1][1]=s[1][i];
            a[1][2]=s[1][i+1];
            int pre=check(a);
            a[0][1]='x';
            int now=check(a);
            if(now!=pre){
                ans++;
            }
        }
        if(s[1][i]=='.'){
            array<array<char,3>,2> a;
            a[0][0]=s[0][i-1];
            a[0][1]=s[0][i];
            a[0][2]=s[0][i+1];
            a[1][0]=s[1][i-1];
            a[1][1]=s[1][i];
            a[1][2]=s[1][i+1];
            int pre=check(a);
            a[1][1]='x';
            int now=check(a);
            if(now!=pre){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}