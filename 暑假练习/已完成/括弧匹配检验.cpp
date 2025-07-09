/*
假设表达式中允许包含两种括号：圆括号和方括号，其嵌套的顺序随意，如（［ ］（））或［（［ ］［ ］）］等为正确的匹配，［（ ］）或（［ ］（ ）或 ( ( ) ) ）均为错误的匹配。
现在的问题是，要求检验一个给定表达式中的括弧是否正确匹配？
输入一个只包含圆括号和方括号的字符串，判断字符串中的括号是否匹配，匹配就输出“OK” ，不匹配就输出“Wrong”。输入一个字符串：［（［］［］）］，输出：OK
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int top,st[maxn];
int main(){
    cin>>s;
    for(unsigned int i=0;i<s.length();i++){
        if(s[i]=='('){
            st[++top]=1;
        }else if(s[i]==')'){
            if(st[top]==1){
                top--;
            }else{
                cout<<"Wrong"<<endl;
                return 0;
            }
        }else if(s[i]=='['){
            st[++top]=2;
        }else{
            if(st[top]==2){
                top--;
            }else{
                cout<<"Wrong"<<endl;
                return 0;
            }
        }
    }
    if(top>0){
        cout<<"Wrong"<<endl;
    }else{
        cout<<"OK"<<endl;
    }
    return 0;
}