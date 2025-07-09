#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m;

int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct node{
    ll x,y;
    node(ll x=0,ll y=0):x(x),y(y){}
    node operator -(const node &a)const{
        return node(x-a.x,y-a.y);
    }
    int operator *(const node &a)const{
        return x*a.y-y*a.x;
    }
}a[N];

int sta[N], top;  // 将凸包上的节点编号存在栈里，第一个和最后一个节点编号相同

ll pf(ll x) { return x * x; }

ll dis(int p, int q) { return pf(a[p].x - a[q].x) + pf(a[p].y - a[q].y); }

ll sqr(int p, int q, int y) { return abs((a[q] - a[p]) * (a[y] - a[q])); }

void get_longest(ll &mx) {  // 求凸包直径
  int j = 3;
  if (top <= 4) {
    mx = max(mx, dis(1, 2));
    mx = max(mx, dis(1, 3));
    mx = max(mx, dis(2, 3));
    return;
  }
  for (int i = 1; i < top; ++i) {
    while (sqr(sta[i], sta[i + 1], sta[j]) <=
           sqr(sta[i], sta[i + 1], sta[j % top + 1]))
      j = j % top + 1;
    mx = max(mx, max(dis(sta[i + 1], sta[j]), dis(sta[i], sta[j])));
  }
}

void solve()
{
    m=read();
    vector<node> A(m+1);
    for(int i=1;i<=m;i++)
        A[i].x=read(),A[i].y=read();
    long double res=0;
    for(int i=1;i<m;i++)
        res+=sqrt((A[i].x-A[i+1].x)*(A[i].x-A[i+1].x)+(A[i].y-A[i+1].y)*(A[i].y-A[i+1].y));
    res+=sqrt((A[m].x-A[1].x)*(A[m].x-A[1].x)+(A[m].y-A[1].y)*(A[m].y-A[1].y));
    n=read();
    for(int i=1;i<=n;i++)
        a[i].x=read(),a[i].y=read();
    top=0;
    for(int i=1;i<=n;i++)
        sta[++top]=i;
    sta[++top]=1;
    ll mx=0;
    get_longest(mx);
    cout<<fixed<<setprecision(15);
    cout<<res+acos(-1)*sqrt(mx)*2<<endl;
}
signed main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}