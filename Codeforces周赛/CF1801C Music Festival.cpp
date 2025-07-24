#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int mx[maxn],p[maxn],num[maxn],ans[maxn],f_ans[maxn];
vector<int>a[maxn];
deque<int>q;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1,k,top;i<=n;i++){
            cin>>k;
            p[i]=i;
            mx[i]=0;
            a[i].clear();
            a[i].push_back(0);
            top=0;
            for(int j=1,x;j<=k;j++){
                cin>>x;
                if(top==0||num[top]<x)
                    num[++top]=x;
                mx[i]=max(mx[i],x);
            }
            for(int j=1;j<=top;j++)
                a[i].push_back(num[j]);
        }
        sort(p+1,p+n+1,[](int x,int y){return mx[x]<mx[y];});
        int top=0;
        for(int i=n;i;i--){
            if(!top){
                ans[++top]=p[i];
            }else{
                int num=a[p[i]].back();
                int pos=upper_bound(a[ans[top]].begin(),a[ans[top]].end(),num)-a[ans[top]].begin()-1;
                if(a[p[i]].back()==a[ans[top]][pos]&&pos+1<a[p[i]].size())
                    ans[++top]=p[i];
                else if(a[p[i]].back()>a[ans[top]][pos]&&pos+1<=a[p[i]].size())
                    ans[++top]=p[i];
            }
        }
        int cnt=0;
        for(int i=top;i;i--){
            for(auto j:a[ans[i]])
                if(f_ans[cnt]<j)
                    f_ans[++cnt]=j;
        }
        cout<<cnt<<endl;
    }
    return 0;
}