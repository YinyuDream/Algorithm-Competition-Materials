//Powered by Myself
#include<bits/stdc++.h>
using namespace std;
string s;
vector<pair<int,int>> Find_All_Biggest_Brackets(int l,int r)
{
    vector<pair<int,int>> pos;
    stack<int> left_bracket;
    for(int i=l;i<=r;i++){
        if(s[i]=='('){
            left_bracket.push(i);
        }else if(s[i]==')'){
            if(left_bracket.size()==1){
                pos.push_back(make_pair(left_bracket.top(),i));
            }
            left_bracket.pop();
        }
    }
    return pos;
}
vector<pair<int,int>> Find_All_Multiplication(vector<string> Infix)
{
    vector<int> pos;
    vector<pair<int,int>>ans;
    for(unsigned int i=0;i<Infix.size();i++){
        if(Infix[i]=="*"||Infix[i]=="/"){
            if(pos.size()&&i-pos[pos.size()-1]>2){
                ans.push_back(make_pair(pos.front(),pos[pos.size()-1]));
                pos.clear();
            }
            pos.push_back(i);
        }
    }
    if(pos.size()){
        ans.push_back(make_pair(pos.front(),pos[pos.size()-1]));
    }
    return ans;
}
string Constructing_Postfix_Expression_Singal_Optition(vector<string> Infix,int l,int r)
{
    string ans=Infix[l];
    for(int i=l+1;i<=r;i+=2){
        ans+=Infix[i+1]+Infix[i];
    }
    return ans;
}
string Constructing_Postfix_Expression_Multi_Optition(vector<string> Infix)
{
    vector<pair<int,int>> Multiplication=Find_All_Multiplication(Infix);
    if(Multiplication.empty()){
        return Constructing_Postfix_Expression_Singal_Optition(Infix,0,Infix.size()-1);
    }else{
        vector<string> New_Infix;
        for(int i=0;i<=Multiplication[0].first-2;i++)
            New_Infix.push_back(Infix[i]);
        for(unsigned int i=0;i<Multiplication.size();i++){
            New_Infix.push_back(Constructing_Postfix_Expression_Singal_Optition(Infix,Multiplication[i].first-1,Multiplication[i].second+1));
            if(i+1u<Multiplication.size()){
                for(int j=Multiplication[i].second+2;j<=Multiplication[i+1].second-2;j++){
                    New_Infix.push_back(Infix[j]);
                }
            }else{
                for(unsigned int j=Multiplication[i].second+2;j<Infix.size();j++){
                    New_Infix.push_back(Infix[j]);
                }
            }
        }
        return Constructing_Postfix_Expression_Singal_Optition(New_Infix,0,New_Infix.size()-1);
    }
}
string solve(int l,int r)
{
    vector<pair<int,int>> Brackets=Find_All_Biggest_Brackets(l,r);
    vector<string> Infix;
    if(Brackets.empty()){
        for(int i=l;i<=r;i++){
            Infix.push_back(string(1,s[i]));
        }
        return Constructing_Postfix_Expression_Multi_Optition(Infix);
    }else{
        for(int i=l;i<=Brackets[0].first-1;i++){
            Infix.push_back(string(1,s[i]));
        }
        for(unsigned int i=0;i<Brackets.size();i++){
            Infix.push_back(solve(Brackets[i].first+1,Brackets[i].second-1));
            if(i+1<Brackets.size()){
                for(int j=Brackets[i].second+1;j<=Brackets[i+1].first-1;j++){
                    Infix.push_back(string(1,s[j]));
                }
            }else{
                for(int j=Brackets[i].second+1;j<=r;j++){
                    Infix.push_back(string(1,s[j]));
                }
            }
        }
        return Constructing_Postfix_Expression_Multi_Optition(Infix);
    }
}
int main(){
    cin>>s;
    cout<<solve(0,s.size()-1);
    return 0;
}

//Powered by ChatGPT
/*
#include <iostream>
#include <stack>
#include <string>

bool IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int GetOperatorPrecedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

std::string ConvertToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operatorStack;

    for (char c : infix) {
        if (isalnum(c)) {  // 操作数直接输出
            postfix += c;
        } else if (c == '(') {  // 左括号入栈
            operatorStack.push(c);
        } else if (c == ')') {  // 右括号处理
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }

            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();  // 弹出对应的左括号
            }
        } else if (IsOperator(c)) {  // 运算符处理
            while (!operatorStack.empty()
                    && operatorStack.top() != '('
                    && GetOperatorPrecedence(c) <= GetOperatorPrecedence(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }

            operatorStack.push(c);
        }
    }

    // 将栈中剩余的运算符弹出
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression;
    std::cout << "请输入中缀表达式：";
    std::cin >> infixExpression;

    std::string postfixExpression = ConvertToPostfix(infixExpression);
    std::cout << "后缀表达式为：" << postfixExpression << std::endl;

    return 0;
}
*/