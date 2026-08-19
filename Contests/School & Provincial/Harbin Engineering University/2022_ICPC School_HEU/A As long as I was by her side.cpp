#include<bits/stdc++.h>
using namespace std;
const int maxn=15010;
int T,n,c[4];
pair<int,int>a[maxn];
deque<pair<int,int> >q;
int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[j].first);
            a[j].second=a[j].first%3;
            c[a[j].second]++;
        }
        int t=0x7f7f7f7f;
        t=min(min(c[0],c[1]),c[2]);
        for(int j=1;j<=t;j++){
        	q.push_back(make_pair(1,));
        	q.push_back(2);
        	q.push_back(3);
		}
		c[0]-=t,c[1]-=t,c[2]-=t;
		
    }
}