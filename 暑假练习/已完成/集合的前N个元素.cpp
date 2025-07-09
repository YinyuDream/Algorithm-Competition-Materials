#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt;
int a[maxn];
priority_queue<int,vector<int>,greater<int> > q;
set<int> set_a;
int main(){
    cin>>n;
    q.push(1);
    set_a.insert(1);
    while(cnt<n){
        int num=q.top();
        q.pop();
        a[++cnt]=num;
        if(!set_a.count(num*2+1)){
            q.push(num*2+1);
            set_a.insert(num*2+1);
        }
        if(!set_a.count(num*3+1)){
            q.push(num*3+1);
            set_a.insert(num*3+1);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}