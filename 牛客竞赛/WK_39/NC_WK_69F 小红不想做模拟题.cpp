#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,q,ans;
int a[maxn],b[maxn];
set<int> pos1,pos2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch=getchar();
        while(ch!='0'&&ch!='1')
            ch=getchar();
        a[i]=ch-'0';
        if(a[i]==0)
            pos1.insert(i);
    }
    for(int i=1;i<=n;i++){
        char ch=getchar();
        while(ch!='0'&&ch!='1')
            ch=getchar();
        b[i]=ch-'0';
        if(b[i]==0)
            pos2.insert(i);
    }
    for(int i=1;i<=n;i++)
        ans+=a[i]&b[i];
    cin>>q;
    for(int i=1;i<=q;i++){
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='A'){
            auto pos=pos1.lower_bound(l);
            for(auto i=pos;i!=pos1.end();i++){
                if(*i>r)break;
                if(((a[*i]&b[*i])==0)&&((1&b[*i])==1))
                    ans++;
                a[*i]=1;
            }
        }else{
            auto pos=pos2.lower_bound(l);
            for(auto i=pos;i!=pos2.end();i++){
                if(*i>r)break;
                if(((a[*i]&b[*i])==0)&&((a[*i]&1)==1))
                    ans++;
                b[*i]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}