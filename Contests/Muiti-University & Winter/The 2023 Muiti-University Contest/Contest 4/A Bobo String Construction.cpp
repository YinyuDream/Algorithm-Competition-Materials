#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE (int)(2e6+10)

int nex[SIZE];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		int len=str.length();
		if(len==1)
		{
			string b;
			if(str[0]=='0') for(int i=0;i<n;i++) b+='1';
			else for(int i=0;i<n;i++) b+='0';
			cout<<b<<endl;
			continue;
		}
		string cop=str;
		int j = 0;
		for(int i=1; i<str.length(); ++i){
			// 当这一位不匹配时，将j指向此位之前最大公共前后缀的位置
			while(j>0 && str[i]!=str[j]) j=nex[j-1];
			// 如果这一位匹配，那么将j+1，继续判断下一位
			if(str[i]==str[j]) ++j;
			// 更新next[i]的值
			nex[i] = j;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(str[j]=='0') str+='1';
			else str+='0';
			while(j>0&&str[i+len-1]!=str[j]) j=nex[j-1];
			if(str[i+len-1]==str[j]) ++j;
			nex[i+len-1]=j;
		}
		str+=cop;
		j=nex[len+n-1];
		int Max=INT_MIN;
		for(int i=len+n;i<len+n+cop.length()-1;i++)
		{
			while(j>0&&str[i]!=str[j]) j=nex[j-1];
			if(str[i]==str[j]) ++j;
			nex[i]=j;
			Max=max(Max,j);
		}
		if(Max>=cop.length()) {cout<<-1<<endl;}
		else{
			cout<<str.substr(len,n)<<endl;
		}
	}
	system("pause");
	return 0;
}