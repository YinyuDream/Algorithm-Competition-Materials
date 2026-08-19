#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,p=998244353;
int n,m,ans;
int f[2][10][10][10][10];
int main(){
    cin>>n>>m;
    for(int a1=1;a1<=9;a1+=2)
        for(int a2=0;a2<=8;a2+=2)
            for(int a3=1;a3<=9;a3+=2)
                for(int a4=0;a4<=8;a4+=2)
                    for(int a5=1;a5<=9;a5+=2)
                        if(a1+a2+a3+a4<m)
                            f[0][a1][a2][a3][a4]=1;
    for(int i=5;i<=n;i++){
        if(i%2==1){
            memset(f[1],0,sizeof f[1]);
            for(int a5=1;a5<=9;a5+=2)
                for(int a4=0;a4<=8;a4+=2)
                    for(int a3=1;a3<=9;a3+=2)
                        for(int a2=0;a2<=8;a2+=2)
                            for(int a1=1;a1<=9;a1+=2)
                                if(a1+a2+a3+a4+a5<=m)
                                    f[1][a2][a3][a4][a5]=(f[1][a2][a3][a4][a5]+f[0][a1][a2][a3][a4])%p;
        }else{
            memset(f[0],0,sizeof f[0]);
            for(int a5=0;a5<=8;a5+=2)
                for(int a4=1;a4<=9;a4+=2)
                    for(int a3=0;a3<=8;a3+=2)
                        for(int a2=1;a2<=9;a2+=2)
                            for(int a1=0;a1<=8;a1+=2)
                                if(a1+a2+a3+a4+a5<=m)
                                    f[0][a2][a3][a4][a5]=(f[0][a2][a3][a4][a5]+f[1][a1][a2][a3][a4])%p;
        }
    }
    for(int a1=0;a1<=9;a1++)
        for(int a2=0;a2<=9;a2++)
            for(int a3=0;a3<=9;a3++)
                for(int a4=0;a4<=9;a4++)
                    ans=(ans+f[n&1][a1][a2][a3][a4])%p;
    cout<<ans<<endl;
    return 0;
}