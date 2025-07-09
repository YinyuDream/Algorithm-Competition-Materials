#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int k;
char A[maxn],C[maxn],B[maxn],B_state[maxn];
int nextn[maxn],can[maxn];
struct node{
	int son[26];
	int fail,flag;
    vector<int> end;
}tree[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(int x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
void clear(int n)
{
    for(int i=0;i<=k;i++){
        memset(tree[i].son,0,sizeof(tree[i].son));
        tree[i].end.clear();
        tree[i].fail=tree[i].flag=0;
    }
    k=0;
    for(int i=0;i<=n;i++)
        can[i]=0;
}
void build(char *a,int eth)
{
	int l=strlen(a),id=0;
	for(int i=0;i<l;i++){
		int t=a[i]-'a';
		if(tree[id].son[t]==0){
			tree[id].son[t]=++k;
		}
		id=tree[id].son[t];
	}
	tree[id].end.push_back(eth);
    tree[id].flag++;
}
void fail_point()
{
    queue<int> q;
	int id=0;
	for(int i=0;i<26;i++){
		int j=tree[id].son[i];
		if(j!=0){
			tree[id].fail=id;
			q.push(j);
		}
	}
	while(q.size()){
		int now=q.front();q.pop();
		for(int i=0;i<26;i++){
			int j=tree[now].son[i];
			if(j==0){
				tree[now].son[i]=tree[tree[now].fail].son[i];
				continue;
			}
			tree[j].fail=tree[tree[now].fail].son[i];
			q.push(j);
		}
	}
}
void serach(char *a)
{
	int id=0,l=strlen(a);
	for(int i=0;i<l;i++){
		int j=tree[id].son[a[i]-'a'];
		while(j&&tree[j].flag!=-1){
			for(auto x:tree[j].end)
                can[x]++;
			tree[j].flag=-1;
			j=tree[j].fail;
		}
		id=tree[id].son[a[i]-'a'];
	}
}

bool kmp(char *a,char *b)
{
    int l1=strlen(a),l2=strlen(b);
    if(l1<l2)
        return false;
    for(int i=0;i<=l1;i++){
        nextn[i]=0;
    }
    int j=0;
	for(int i=1;i<l2;i++){
		while(b[i]!=b[j]&&j)
			j=nextn[j-1];
		j+=(b[i]==b[j]);
		nextn[i]=j;
	}
    j=0;
	for(int i=0;i<l1;i++){
		while(a[i]!=b[j]&&j)
			j=nextn[j-1];
		j+=(a[i]==b[j]);
		if(j==l2)
			return true;
	}
    return j==l2;
}
void solve(){
    int n=read();
    scanf("%s%s",A,C);
    for(int i=0;i<n;i++){
        scanf("%s%s",B,B_state);
        build(B,i);
        can[i]+=kmp(B_state,C);
    }
    fail_point();
    serach(A);
    vector<int> ans;
    for(int i=0;i<n;i++)
        if(can[i]==2)
            ans.push_back(i);
    clear(n);
    if(ans.empty()){
        puts("");
        return;
    }
    for(auto x:ans){
        write(x+1);
        putchar(" \n"[x==ans.back()]);
    }
}
int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}