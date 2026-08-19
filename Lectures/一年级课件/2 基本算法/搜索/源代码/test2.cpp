#include<iostream>
using namespace std;
int n,m,total=0;
bool f[10];
int ac[10];
void init()
{
    freopen("zuhe.in","r",stdin);
    freopen("zuhe.out","w",stdout);
    cin>>n>>m;
}
void print()
{
     for(int j=0;j<m;j++)
    {
        cout<<ac[j];
    }
    cout<<endl;
    total++;
}
void dfs(int x,int k)
{
    if(k==m)
    {
        print();
    }
    else
    {
        for(int i=x;i<=n;i++)
        {
            if(f[i])
            {
                f[i]=false;
                ac[k]=i;
                dfs(i+1,k+1);
                f[i]=true;
           }
        }
    }
}
int main()
{
    init();
    for(int i=1;i<=n;i++) f[i]=true;
    dfs(1,0);
    cout<<total<<endl;
    while(1);
    return 0;
}
