#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
template <typename T>
inline void _read(T& x){
    char ch=getchar();bool sign=true;
    while(!isdigit(ch)){if(ch=='-')sign=false;ch=getchar();}
    for(x=0;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
    if(!sign)x=-x;
}
int T,n,x,y;
int a[100005];
void rev(int l,int r){//a[l]..a[r] 
    int i,lim=(l+r)/2;
    for(i=l;i<=lim;i++)swap(a[i],a[r+l-i]);
}
int main(){
    int i,j,k;
        _read(n);_read(x);_read(y);
        if(1ll*x*y<n||x+y>n+1){
            puts("NO");
            return 0;
        }
        for(i=1;i<=n;i++)a[i]=i;
        rev(n-y+1,n);
        int temp=n-y+1-x,pos=n-y;
        while(temp){
            if(temp<y){
                rev(pos-temp,pos);
                break;
            }
            else {
                rev(pos-y+1,pos);
                temp-=(y-1);
                pos-=y;
            }
        }
        puts("YES");
        for(i=1;i<=n;i++){
            if(i<n)printf("%d ",a[i]);
            else printf("%d\n",a[i]);
        }
}
