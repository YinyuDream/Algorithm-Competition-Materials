#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100005;

typedef pair<int,int> ii;

int n;
int t[MAXN];
vector<ii> e;
int uf[MAXN], mv[MAXN];

bool cmp(const ii& a, const ii& b) {
    int x = max(t[a.first], t[a.second]);
    int y = max(t[b.first], t[b.second]);
    return x<y;
}
int fnd(int x){
    if(x==uf[x]) return x;
    else return uf[x]=fnd(uf[x]);
}

long long sol = 0;

void un(int x, int y){
    x = fnd(x);
    y = fnd(y);
    if(x != y){
        sol += mv[x] + mv[y];
        mv[y] = max(mv[y], mv[x]);    
        uf[x] = y;
    }
}

int main(){

  freopen("delete.in","r",stdin);
  freopen("delete.out","w",stdout);
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &t[i]);
        uf[i] = i;
        mv[i] = t[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d", &u, &v);
        e.push_back(ii(u-1, v-1));
    }
    sort(e.begin(), e.end(), cmp);
    for(auto i:e){
        un(i.first, i.second);
    }
    printf("%lld\n", sol);
}
