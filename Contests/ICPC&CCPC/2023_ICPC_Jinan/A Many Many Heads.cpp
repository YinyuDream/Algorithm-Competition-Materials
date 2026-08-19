#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,top;
char s[maxn],a[maxn];
char st[maxn];
struct node{
    int dep;
    char ch;
}st2[maxn];
bool same_col(char l,char r)
{
    int col_l,col_r;
    if(l=='('||l==')')col_l=1;
    else col_l=2;
    if(r=='('||r==')')col_r=1;
    else col_r=2;
    return col_l==col_r;
}
bool work()
{
    top=0;
    cin>>(s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='['||s[i]==']'){
            if(top==0||st[top]=='('){
                a[i]='[';
                st[++top]='[';
            }else{
                a[i]=']';
                top--;
            }
        }else{
            if(top==0||st[top]=='['){
                a[i]='(';
                st[++top]='(';
            }else{
                a[i]=')';
                top--;
            }
        }
    }
    top=0;
    a[n+1]=')';
    for(int i=1;i<=n+1;i++){
        int deep=st2[top].dep;
        if(a[i]=='('){
            if(top==0||st2[top].ch=='['||st2[top].ch=='(')st2[++top]={deep+1,'('};
            else st2[++top]={deep,'('};
        }
        if(a[i]=='['){
            if(top==0||st2[top].ch=='['||st2[top].ch=='(')st2[++top]={deep+1,'['};
            else st2[++top]={deep,'['};
        }
        if(a[i]==')'){
            if(st2[top].ch=='(')
                st2[++top]={deep,')'};
            else{
                if((top>=6&&st2[top-5].dep==st2[top].dep)||(top>=4&&st2[top-3].dep==st2[top].dep&&same_col(st2[top-3].ch,st2[top].ch)))
                    return true;
                int dep=st2[top].dep;
                while(st2[top].dep==dep)top--;
                st2[++top]={deep-1,')'};
            }
        }
        if(a[i]==']'){
            if(st2[top].ch=='[')
                st2[++top]={deep,']'};
            else{
                if((top>=6&&st2[top-5].dep==st2[top].dep)||(top>=4&&st2[top-3].dep==st2[top].dep&&same_col(st2[top-3].ch,st2[top].ch)))
                    return true;
                int dep=st2[top].dep;
                while(st2[top].dep==dep)top--;
                st2[++top]={deep-1,']'};
            }
        }
    }
    return false;
}
int main(){
    cin>>T;
    while(T--){
        cout<<(work()?"No":"Yes")<<endl;
    }
    return 0;
}