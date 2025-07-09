#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn];
deque<int>q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        if(q.empty())q.push_back(a[i]);
        else{
            if(q.back()!=a[i])q.push_back(a[i]);
            else{
                while(q.size()&&q.back()==a[i]){
                    a[i]++;
                    q.pop_back();
                }
                q.push_back(a[i]);
            }
        }
    }
    cout<<q.size()<<endl;
    return 0;
}