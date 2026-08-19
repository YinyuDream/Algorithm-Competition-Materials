#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
long long F[20][10][15][2]; 
int c[100];
long long Cal(int x,int p,int sum,int flag1,int flag){
    if(!x)return sum;
    if(!flag&&F[x][p][sum][flag1])return F[x][p][sum][flag1];
    int k=flag?c[x]:9;
    long long ret=0;
    for(int i=0;i<=k;i++){
        ret+=Cal(x-1,p,sum+((i==p)&&((flag1&&p==0)||(p!=0))),flag1||(i!=0),flag&&(i==k));
    }
    return flag?ret:F[x][p][sum][flag1]=ret;
}
long long Ask(long long x,int k){
    c[0]=0;
    while(x){c[++c[0]]=x%10;x/=10;}
    return Cal(c[0],k,0,0,1);
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    for(int i=0;i<=8;i++){
        printf("%lld ",Ask(b,i)-Ask(a-1,i));
    }printf("%lld",Ask(b,9)-Ask(a-1,9));
    return 0;
}
