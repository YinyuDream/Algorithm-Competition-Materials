#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
const int p=1e9+7;
int n,m;
struct poly{
    vector<int> a;
    poly(vector<int> _a){
        a=_a;
    }
};
vector<string> cal;
stack<poly> st;
int num[maxn];
poly operator *(poly u,poly v)
{
    int len=u.a.size()+v.a.size()-2;
    vector<int> ans(len+1);
    for(unsigned int i=0;i<=len;i++){
        ans[i]=0;
        for(unsigned int j=0;j<=i;j++){
            int _u=(j<u.a.size())?u.a[j]:0;
            int _v=((i-j)<v.a.size())?v.a[i-j]:0;
            ans[i]=(ans[i]+1ll*_u*_v)%p;
        }
    }
    return poly(ans);
}
poly operator +(poly u,poly v)
{
    int len=max(u.a.size(),v.a.size());
    vector<int> ans(len);
    for(int i=0;i<len;i++){
        int _u=(i<u.a.size())?u.a[i]:0;
        int _v=(i<v.a.size())?v.a[i]:0;
        ans[i]=(1ll*_u+_v)%p;
    }
    return ans;
}
poly operator -(poly u,poly v)
{
    int len=max(u.a.size(),v.a.size());
    vector<int> ans(len);
    for(int i=0;i<len;i++){
        int _u=(i<u.a.size())?u.a[i]:0;
        int _v=(i<v.a.size())?v.a[i]:0;
        ans[i]=(1ll*_u-_v)%p;
    }
    return ans;
}
int dif(int pos)
{
    int pw[111];
    pw[0]=1;
    for(int i=1;i<=110;i++)
        pw[i]=1ll*pw[i-1]*num[pos]%p;
    vector<int> now=st.top().a;
    int ans=0;
    for(auto i=now.begin()+1;i<now.end();i++){
        int npw=i-now.begin();
        ans=(ans+1ll*npw*now[npw]%p*pw[npw-1]%p)%p;
    }
    return (ans+p)%p;
}
void init()
{
    char s[1100];
    int top=0;
    memset(s,0,sizeof s);
    while(true){
        char ch;
        ch=getchar();
        if(top&&ch=='\n'){
            s[++top]=ch;
            break;
        }
        s[++top]=ch;
    }
    int lst=1;
    for(int i=2;i<=top;i++){
        if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='x'&&(s[i]<'0'||s[i]>'9')){
            string tmp;
            for(int j=lst+1;j<=i-1;j++)
                tmp.push_back(s[j]);
            lst=i;
            cal.push_back(tmp);
        }
    }
}
int ask(auto l,auto r)
{
    int ans=0;
    for(auto i=l;i<=r;i++)
        ans=ans*10+*i-'0';
    return ans;
}
void work(int pos)
{
    while(st.size())
        st.pop();
    for(auto i:cal){
        if(i[0]=='x'){
            int t=ask(i.begin()+1,i.end()-1);
            if(t!=pos){
                vector<int> v(1);
                v[0]=num[t];
                st.push(poly(v));
            }else{
                vector<int> v(2);
                v[0]=0,v[1]=1;
                st.push(poly(v));
            }
        }else if(i[0]=='*'){
            poly u=st.top();
            st.pop();
            poly v=st.top();
            st.pop();
            poly ans=u*v;
            st.push(ans);
        }else if(i[0]=='+'){
            poly u=st.top();
            st.pop();
            poly v=st.top();
            st.pop();
            poly ans=u+v;
            st.push(ans);
        }else if(i[0]=='-'){
            if(i.size()==1){
                poly u=st.top();
                st.pop();
                poly v=st.top();
                st.pop();
                poly ans=v-u;
                st.push(ans);
            }else{
                int t=ask(i.begin()+1,i.end()-1);
                vector<int> v(1);
                v[0]=-t;
                st.push(poly(v));
            }
        }else{
            int t=ask(i.begin(),i.end()-1);
            vector<int> v(1);
            v[0]=t;
            st.push(poly(v));
        }
        
    }
    cout<<dif(pos)<<endl;
}
int main(){
    cin>>n>>m;
    init();
    for(int i=1,pos;i<=m;i++){
        cin>>pos;
        for(int j=1;j<=n;j++)
            cin>>num[j];
        work(pos);
    }
    return 0;
}