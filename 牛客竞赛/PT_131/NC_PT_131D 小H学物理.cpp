#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Segment_Tree{
    private:
        int n;
        struct node{
            int l,r;
            ll sum,lazy;
        };
        vector<node> tree;
    public:
        Segment_Tree(int n):n(n){
            tree.resize(4*n+10);
        }
        void build(int l,int r,int k){
            tree[k].l=l,tree[k].r=r;
            if(l==r){
                tree[k].sum=0;
                return;
            }
            int mid=(l+r)/2;
            build(l,mid,k*2);
            build(mid+1,r,k*2+1);
            tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
        }
        // 维护：区间加等差数列
        
}
int main(){
    return 0;
}