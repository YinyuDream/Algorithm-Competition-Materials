#include<bits/stdc++.h>
using namespace std;
int const maxn=10001;
struct node{
    int f,d;
    bool operator <(node x)const{
        return f<x.f;
    }
}a[maxn];
int n,h,i,j,k,d[maxn],t[maxn],ans,H;
priority_queue<node>q;
int main(){
    cin>>n>>H;
    H*=12;
    for(i=1;i<=n;++i)
        cin>>a[i].f;
    for(i=1;i<=n;++i)
        cin>>a[i].d;
    for(i=1;i<n;++i)
        cin>>t[i];
    for(int i=1;i<=n;i++){       
    	h=H;
        for(j=1;j<i;j++)h-=t[j];            
        int now=0;
        while(q.size())q.pop();
        for(j=1;j<=i;++j)  
            q.push(a[j]);
        while(h>0){
           node s;
            s=q.top(); 
			 q.pop();    
                    
            now+=s.f;    
            s.f-=s.d;   
            if(s.f<0) s.f=0;   
            q.push(s);
		      h--;
        }
        ans=max(ans,now);     
    }
    cout<<ans<<endl;
    return 0;
}
