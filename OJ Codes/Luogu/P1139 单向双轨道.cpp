#include<cstdio>
#include<stack>
#include<cstdlib>
#include<queue>
using namespace std;
const int maxn=30;
int n,top;
char m[maxn];
int book;
stack<char>A,B,C,D;
struct node{
	char train,sts,ste;
	node(char train1,char sts1,char ste1){
		train=train1,sts=sts1,ste=ste1;
	}
};
deque<node>st;
void write()
{
	top=0;
	while(st.size())
	{
		node p=st.front();
		printf("%c %c %c\n",p.train,p.sts,p.ste);
		st.pop_front();
	}
}
void dfs(int step,int &deep)
{

	if(step>deep)return ;
	if(step+(n-D.size())>deep)return ;
	if(A.empty()&&B.empty()&&C.empty()){
		write(),exit(0);
	}
	if(A.size()){
		B.push(A.top()),
		A.pop(),
		st.push_back(node(B.top(),'A','B')),
		dfs(step+1,deep),
		A.push(B.top()),
		B.pop(),
		st.pop_back();
		C.push(A.top()),
		A.pop(),
		st.push_back(node(C.top(),'A','C')),
		dfs(step+1,deep),
		A.push(C.top()),
		C.pop(),
		st.pop_back();
		if(m[top+1]==A.top())
		{
			D.push(A.top());
			A.pop();
			top++;
			st.push_back(node(D.top(),'A','D'));
			dfs(step+1,deep);
			A.push(D.top());
			D.pop();
			top--;
			st.pop_back();
		}
		
	}
	if(B.size()){
		C.push(B.top()),
		B.pop(),
		st.push_back(node(C.top(),'B','C')),
		dfs(step+1,deep),
		B.push(C.top()),
		C.pop(),
		st.pop_back();
		if(m[top+1]==B.top())
		{
			D.push(B.top()),
			B.pop(),
			top++,
			st.push_back(node(D.top(),'B','D')),
			dfs(step+1,deep),
			B.push(D.top()),
			D.pop(),
			top--,
			st.pop_back();
		}
	}
	if(C.size()){
		if(m[top+1]==C.top())
		{
			D.push(C.top()),
			C.pop(),
			top++,
			st.push_back(node(D.top(),'C','D')),
			dfs(step+1,deep),
			C.push(D.top()),
			D.pop(),
			top--,
			st.pop_back();
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		A.push(i+'a'-1);
	for(int i=1;i<=n;i++)
		scanf(" %c",&m[n-i+1]);
	for(int i=1;i<=n*3;i++)dfs(0,i);
	printf("NO");
	return 0;
}
