#pragma GCC optimize(3)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace	std;
const int maxn=1e7+10;
char st1[maxn],st2[maxn],que[maxn],a[maxn];
int q,flag,top1,top2,front=maxn/2,back=maxn/2-1,len;
void lsh(int opt){
	if(opt==0){
		if(!top1)puts("F");
		else{
			puts("T");
			if(!flag)que[--front]=st1[top1--];
			else que[++back]=st1[top1--];
		}
	}else{
		if(front<=back){
			puts("T");
			if(!flag)st2[++top2]=que[back--];
			else st2[++top2]=que[front++];
		}
		else if(top1){
			puts("T");
			st2[++top2]=st1[top1--];
		}
		else puts("F");
	}
}//光标左移
void rsh(int opt){
	if(opt==0){
		if(front<=back){
			puts("T");
			if(!flag)st1[++top1]=que[front++];
			else st1[++top1]=que[back--];
		}
		else if(top2){
			puts("T");
			st1[++top1]=st2[top2--];
		}
		else puts("F");
	}else{
		if(!top2)puts("F");
		else{
			puts("T");
			if(!flag)que[++back]=st2[top2--];
			else que[--front]=st2[top2--];
		}
	}
}//光标右移
void add(char num,int opt){
	if(opt==0||front==back+1){
		st1[++top1]=num;
	}else{
		if(!flag)que[++back]=num;
		else que[--front]=num;
	}
	puts("T");
}//在光标处添加字符
void del(int opt){
	if(opt==1||front==back+1){
		if(!top2)puts("F");
		else puts("T"),top2--;
	}else{
		puts("T");
		if(!flag)++front;
		else --back;
	}
}//在光标处删除字符
void rev(){
	if(front==back+1)puts("F");
	else flag^=1,puts("T");
}//翻转光标
void show(){
	for(int i=1;i<=top1;i++)
		printf("%c",st1[i]);
	if(!flag)
		for(int i=front;i<=back;i++)
			printf("%c",que[i]);
	else
		for(int i=back;i>=front;i--)
			printf("%c",que[i]);
	for(int i=top2;i;i--)
		printf("%c",st2[i]);
	puts("");
}//打印当前文本
int main(){
	scanf("%s\n%d",a+1,&q);
	len=strlen(a+1);
	for(int i=1;i<=len;i++)
		que[++back]=a[i];
	for(int i=1;i<=q;i++)
	{
		char opt,x,y;
		scanf("\n%c",&opt);
		if(opt=='<')scanf(" %c",&x),lsh(x=='L'?0:1);
		else if(opt=='>')scanf(" %c",&x),rsh(x=='L'?0:1);
		else if(opt=='I')scanf(" %c %c",&x,&y),add(y,x=='L'?0:1);
		else if(opt=='D')scanf(" %c",&x),del(x=='L'?0:1);
		else if(opt=='R')rev();
		else show();
	}
	return 0;
}