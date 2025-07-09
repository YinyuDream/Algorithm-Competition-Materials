#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
double eps=1e-15;
int T,n;
bool book[maxn];
ll x[maxn],y[maxn];
bool co_line()
{
    for(int i=1;i<=n;i++)
        book[i]=false;
    book[1]=book[2]=true;
    bool flag=true;
    if(x[1]==x[2]){
        for(int i=3;i<=n;i++){
            if(x[i]!=x[1]){
                flag=false;
            }else{
                book[i]=true;
            }
        }
        return flag;
    }else{
        for(int i=3;i<=n;i++){
            if(y[i]*(x[2]-x[1])-(y[2]-y[1])*x[i]!=y[1]*(x[2]-x[1])-x[1]*(y[2]-y[1])){
                flag=false;
            }else{
                book[i]=true;
            }
        }
        return flag;
    }
}
bool check(int pos,vector<int> points)
{
    vector<double>angle;
    for(int i=0;i<points.size();i++)
        if(i!=pos)
            angle.push_back(atan2(y[points[i]]-y[points[pos]],x[points[i]]-x[points[pos]]));
    for(int i=0;i<angle.size();i++)
        for(int j=i+1;j<angle.size();j++)
            if(fabs(angle[j]-angle[i])<eps)
                return false;
    return true;
}
void work()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    if(n<5||co_line()){
        cout<<"NO"<<endl;
        return ;
    }
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    int pos=0;
    for(int i=1;i<=n;i++){
        if(!book[i]){
            v.push_back(i);
            pos=i;
            break;
        }
    }
    for(int i=3;i<=n;i++){
        if(i!=pos)
            v.push_back(i);
        if(v.size()==5)
            break;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<v.size();i++){
        if(check(i,v)){
            cout<<x[v[i]]<<" "<<y[v[i]]<<endl;
            for(int j=0;j<v.size();j++){
                if(i!=j)
                    cout<<x[v[j]]<<" "<<y[v[j]]<<endl;
            }
            return ;
        }
    }
}
int main(){
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}