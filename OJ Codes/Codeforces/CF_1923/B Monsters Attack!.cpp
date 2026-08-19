#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,k,remain,day,flag;
struct node{
    int a,x;
}p[maxn];
bool cmp(node u,node v)
{
    return u.x<v.x;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>p[i].a;
        for(int i=1;i<=n;i++){
            cin>>p[i].x;
            if(p[i].x<0){
                p[i].x=-p[i].x;
            }
        }
        sort(p+1,p+n+1,cmp);
        flag=1;
        for(int i=1,pos=1,remain=0;i<=n;i++){
            remain=k;
            while(remain-p[pos].a>=0){
                remain-=p[pos].a;
                p[pos].a=0;
                pos++;
                if(pos==n+1)goto flag;
            }
            p[pos].a-=remain;
            remain=0;
            if(p[pos].x<=i){
                flag=0;
            }
        }
        flag:;
        if(flag==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
	}
	return 0;
}