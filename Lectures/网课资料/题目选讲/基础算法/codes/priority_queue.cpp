#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
template <typename T>
inline void _read(T& x){
	char ch=getchar();bool sign=true;
	while(!isdigit(ch)){if(ch=='-')sign=false;ch=getchar();}
	for(x=0;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	if(!sign)x=-x;
}
struct node{
	int x,y;
	node(){}
	node(int X,int Y){
		x=X;
		y=Y;
	}
	
	bool operator < (const node& A) const {
		if(x==A.x)return y>A.y;
		else return x>A.x; 
	}
	
}; 
priority_queue<node> q;
/*
int <
3<5
priority_queue<int> q;
*/
int main(){
	node t=node(3,5);
}

