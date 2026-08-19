#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define W 1000000
#define M 4000000 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, q, A[N];
LL ans;
map<int, int> Map;

struct Node
{
    int ucnt, cnt;
    LL sum, diff_sum;
    Node() : Node(0, 0, 0) {}
    Node(int cnt, LL sum, LL diff_sum) : cnt(cnt), sum(sum), diff_sum(diff_sum) {}
}Tree[M];

inline Node Union(const Node &lhs, const Node &rhs)
{
    Node ret;
    ret.ucnt = lhs.ucnt + rhs.ucnt;
    ret.cnt = lhs.cnt + rhs.cnt;
    ret.sum = lhs.sum + rhs.sum;
    ret.diff_sum = lhs.diff_sum + rhs.diff_sum + (lhs.cnt * rhs.sum - rhs.cnt * lhs.sum);
    return ret;
}

void Modify(int x, int l, int r, int t, int k)
{
    if (l == r)
    {
        Tree[x].cnt += k;
        Tree[x].sum += k * l;
        Tree[x].ucnt = Tree[x].cnt > 0 ? 1 : 0;
        return ;
    }
    int mid = l + r >> 1;
    if (t <= mid)
        Modify(ls(x), l, mid, t, k);
    else Modify(rs(x), mid + 1, r, t, k);
    Tree[x] = Union(Tree[ls(x)], Tree[rs(x)]);
}

inline void Add(int pos, int k)
{
    Map[pos] += k;
    if (Map[pos] == 0)
        Map.erase(pos);
    Modify(1, 1, W, pos, k);
}

Node Query(int x, int l, int r, int s, int t)
{
    if (l == s && r == t)
        return Tree[x];
    int mid = l + r >> 1;
    if (t <= mid)
        return Query(ls(x), l, mid, s, t);
    else if (s > mid)
        return Query(rs(x), mid + 1, r, s, t);
    else return Union(Query(ls(x), l, mid, s, mid), Query(rs(x), mid + 1, r, mid + 1, t));
}

inline LL Calc(int x, int d)
{
    int l_cnt = x > 1 ? Query(1, 1, W, 1, x - 1).cnt : 0;
    Node nd = Query(1, 1, W, max(1, x), min(x + d, W));
    int r_cnt = n - l_cnt - nd.cnt;
    nd = Union(Node(l_cnt, LL(l_cnt) * x, 0), nd);
    nd = Union(nd, Node(r_cnt, LL(r_cnt) * (x + d), 0));
    return nd.diff_sum;
}

inline int GetRank(int rk)
{
    int x = 1, l = 1, r = W;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (Tree[ls(x)].ucnt >= rk)
            r = mid, x = ls(x);
        else rk -= Tree[ls(x)].ucnt, l = mid + 1, x = rs(x);
    }
    return l;
}

inline LL CalcRank(int rk, int d, int op)
{
    int val = GetRank(rk);
    return Calc(val - op * d, d);
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Add(A[i], 1);
    }
    for (int op, x, d; q; q --)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &x, &d);
            Add(A[x], -1);
            Add(d, 1);
            A[x] = d;
        }
        else
        {
            scanf("%d", &d);
            int mn = Map.begin()->first, mx = Map.rbegin()->first;
            if (mn + d >= mx)
                ans = Tree[1].diff_sum;
            else
            {
                ans = 0;
                for (int op = 0; op < 2; op ++)
                {
                    int l = 1, r = Tree[1].ucnt;
                    while (l < r)
                    {
                    	int mid = (l + r) >> 1;
                        LL val_l = CalcRank(mid, d, op);
                        LL val_r = CalcRank(mid + 1, d, op);
                        if (val_l >= val_r)
                            r = mid;
                        else l = mid + 1;
                    }
                    ans = max(ans, CalcRank(l, d, op));
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}