#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;

}
int g(int a,int b)
{
    if(a==0)return 0;
    if(b==0)return 1;
    int l=min(a,b),r=max(a,b);
    if(r/l>=2){
        int num=r%l+l;
        bool rev=((r-num)/l)%2;
        int val=0;
        if(a>b){
            if(!rev){
                val=(r-num)/(2*l)*3;
            }else{
                int t=num+l;
                val=(r-t)/(2*l)*3+1;
            }
        }else{
            if(!rev){
                val=(r-num)/(2*l)*3;
            }else{
                int t=num+l;
                val=(r-t)/(2*l)*3+2;
            }
        }
        if(!rev){
            if(a<b){
                return val+g(l,num);
            }else return val+g(num,l);
        }else{
            if(a<b){
                return val+g(num,l);
            }else return val+g(l,num);
        }
    }else{
        return g(b,abs(a-b))+1;
    }
}
int main(){
    T=read();
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            a[i]=read();
        for(int i=1;i<=n;i++)
            b[i]=read();
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(a[i]||b[i]){
                int ans=g(a[i],b[i])%3;
                for(int j=i+1;j<=n;j++){
                    if(a[j]||b[j]){
                        if(ans!=g(a[j],b[j])%3){
                            flag=false;
                        }
                    }
                }
                goto end;
            }
        }
        end:;
        if(flag)puts("YES");
        else puts("NO");
    }
	return 0;
}