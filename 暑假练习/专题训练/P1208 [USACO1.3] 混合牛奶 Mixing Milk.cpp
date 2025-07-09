    #include<bits/stdc++.h>
    using namespace std;
    const int maxn=1e6+10;
    int n,m,prime,num;
    struct node{
        int p,a;
    }f[maxn];
    bool cmp(node a,node b)
    {
        return a.p<b.p;
    }
    int main(){
        cin>>n>>m;
        for(int i=1;i<=m;i++)
            cin>>f[i].p>>f[i].a;
        sort(f+1,f+m+1,cmp);
        for(int i=1;i<=m;i++){
            if(num+f[i].a>=n){
                prime+=(n-num)*f[i].p;
                break;
            }else{
                prime+=f[i].p*f[i].a;
                num+=f[i].a;
            }
        }
        cout<<prime<<endl;
        return 0;
    }