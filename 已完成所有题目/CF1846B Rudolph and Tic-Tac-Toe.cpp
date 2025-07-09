#include<bits/stdc++.h>
using namespace std;
int T;
char s[3][3];
bool check(char ch)
{
	bool ans=false;
	if(s[0][0]==s[1][1]&&s[1][1]==s[2][2]&&s[2][2]==ch)ans=true;
	if(s[0][2]==s[1][1]&&s[1][1]==s[2][0]&&s[2][0]==ch)ans=true;
	if(s[0][0]==s[0][1]&&s[0][1]==s[0][2]&&s[0][2]==ch)ans=true;
	if(s[1][0]==s[1][1]&&s[1][1]==s[1][2]&&s[1][2]==ch)ans=true;
	if(s[2][0]==s[2][1]&&s[2][1]==s[2][2]&&s[2][2]==ch)ans=true;
	if(s[0][0]==s[1][0]&&s[1][0]==s[2][0]&&s[2][0]==ch)ans=true;
	if(s[0][1]==s[1][1]&&s[1][1]==s[2][1]&&s[2][1]==ch)ans=true;
	if(s[0][2]==s[1][2]&&s[1][2]==s[2][2]&&s[2][2]==ch)ans=true;
	return ans;
}
int main(){
	cin>>T;
	while(T--){
		for(int i=0;i<=2;i++)
			cin>>s[i];
		if(check('+'))cout<<'+'<<endl;
		else if(check('O'))cout<<'O'<<endl;
		else if(check('X'))cout<<'X'<<endl;
		else cout<<"DRAW"<<endl;
	}
	return 0;
}