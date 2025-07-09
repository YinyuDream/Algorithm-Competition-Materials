#include<bits/stdc++.h>
using namespace std;
const int N=1005;
#define pii pair<int,int>
int gcd[N][N],book[N][N];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    int n=read();
    vector<pii> v;
    vector<int> bookx(n+1),booky(n+1);
    auto slope=[](pii a,pii b){
        int x=a.first-b.first,y=a.second-b.second;
        if(y<0){
            x=-x;
            y=-y;
        }
        if(!y&&x<0)
            x=-x;
        int g=__gcd(abs(x),abs(y));
        return make_pair(x/g,y/g);
    };
    for(int i=0;i<n*n;i++){
        int x,y;
        x=read(),y=read();
        if(book[x][y]){
            putchar('0');
            continue;
        }
        putchar('1');
        for(auto &p:v){
            pii slp=slope(p,{x,y});
            for(int j=1;x+j*slp.first<=n&&y+j*slp.second<=n&&x+j*slp.first>0&&y+j*slp.second>0;j++)
                book[x+j*slp.first][y+j*slp.second]=1;
            for(int j=1;x-j*slp.first>0&&y-j*slp.second>0&&x-j*slp.first<=n&&y-j*slp.second<=n;j++)
                book[x-j*slp.first][y-j*slp.second]=1;
        }
        v.push_back({x,y});
        book[x][y]=1;
    }
    return 0;
}