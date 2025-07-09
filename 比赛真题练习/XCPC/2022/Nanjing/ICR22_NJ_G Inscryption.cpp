#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int sum=1,tot=1,cnt_1=0,cnt_0=0,cnt_n1=0,can=1;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                cnt_1++;
                sum++;
                tot++;
            }else if(a[i]==-1){
                cnt_n1++;
                if(tot>1){
                    tot--;
                }else{
                    sum++;
                    tot++;
                }
            }else{
                cnt_0++;
                if(tot>1){
                    tot--;
                }else{
                    sum++;
                    tot++;
                }
            }
            if(cnt_1+cnt_0<cnt_n1){
                can=0;
                break;
            }
        }
        if(!can){
            puts("-1");
            continue;
        }
        int gcd=__gcd(sum,tot);
        sum/=gcd;
        tot/=gcd;
        printf("%d %d\n",sum,tot);
    }
    return 0;
}