#include<bits/stdc++.h>
using namespace std;
char zip[128],inv[128];
void init()
{
    int book[128];
    memset(book,0,sizeof book);
    string s;
    getline(cin,s);
    int len=s.size();
    for(int i=0;i<len;i++)
        if(s[i]>='A'&&s[i]<='Z')
            s[i]=s[i]-'A'+'a';
    string t;
    for(int i=0;i<len;i++){
        if(s[i]<'a'||s[i]>'z')
            continue;
        if(book[s[i]]==0){
            book[s[i]]=1;
            t.push_back(s[i]-'a'+'A');
        }
    }
    for(char i='a';i<='z';i++)
        if(book[i]==0)
            t.push_back(i-'a'+'A');
    for(int i=0;i<=25;i++)
        zip[i+'a']=t[i],inv[t[i]]=i+'a';
}
int main(){
    init();
     
    while(true){
        string s;
        getline(cin,s);
        if(s=="END"){
            cout<<"Thanks for using goodbye!"<<endl;
            break;
        }
        if(s=="encryption"){
            getline(cin,s);
            int len=s.size();
            for(int i=0;i<len;i++)
                if(s[i]>='a'&&s[i]<='z')
                    s[i]=zip[s[i]];
            cout<<s<<endl;
        }
        if(s=="decryption"){
            getline(cin,s);
            int len=s.size();
            for(int i=0;i<len;i++)
                if(s[i]>='A'&&s[i]<='Z')
                    s[i]=inv[s[i]];
            cout<<s<<endl;
        }
    }
    return 0;
}