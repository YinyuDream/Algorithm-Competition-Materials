#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=8e6+10;
int ltop,rtop,n,head=maxn,tail=maxn,tag;
char L[maxn*2],R[maxn*2],s[maxn*3],skr[maxn/2],x,y,z;
int main(){
    scanf("%s",skr);
    int len=strlen(skr);
    for(int i=0;i<len;i++) s[tail++]=skr[i];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&x);
        if(x=='<'){
            scanf(" %c",&y);
            if(y=='L'){
                if(!ltop) puts("F");
                else{
                    puts("T");
                    if(!tag) s[--head]=L[ltop--];
                    else s[tail++]=L[ltop--];
                }
            }
            else{
                if(head<tail){
                    puts("T");
                    if(!tag) R[++rtop]=s[--tail];
                    else R[++rtop]=s[head++];
                }
                else if(ltop){
                    puts("T");
                    R[++rtop]=L[ltop--];
                }
                else puts("F");
            }
        }
        else if(x=='>'){
            scanf(" %c",&y);
            if(y=='R'){
                if(!rtop) puts("F");
                else{
                    puts("T");
                    if(tag==0) s[tail++]=R[rtop--];
                    else s[--head]=R[rtop--];
                }
            }
            else{
                if(head<tail){
                    puts("T");
                    if(!tag) L[++ltop]=s[head++];
                    else L[++ltop]=s[--tail];
                }
                else if(rtop){
                    puts("T");
                    L[++ltop]=R[rtop--];
                }
                else puts("F");
            }
        }
        else if(x=='R'){
            if(head==tail) puts("F");
            else tag^=1,puts("T");
        }
        else if(x=='I'){
            scanf(" %c %c",&y,&z);
            if(y=='L'||head==tail) L[++ltop]=z;
            else{
                if(!tag) s[tail++]=z;
                else s[--head]=z;
            }
            puts("T");
        }
        else if(x=='D'){
            scanf(" %c",&y);
            if(y=='R'||head==tail){
                if(!rtop) puts("F");
                else puts("T"),rtop--;
            }
            else{
                puts("T");
                if(!tag) ++head;
                else --tail;
            }
        }
        else{
            for(int j=1;j<=ltop;j++) printf("%c",L[j]);
            if(!tag) for(int j=head;j<tail;j++)  printf("%c",s[j]);
            else for(int j=tail-1;j>=head;j--) printf("%c",s[j]);
            for(int j=rtop;j;j--) printf("%c",R[j]);
            puts("");
        }
    }
    return 0;
}
