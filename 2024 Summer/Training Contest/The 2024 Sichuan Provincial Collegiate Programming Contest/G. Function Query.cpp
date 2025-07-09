#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll n;
int tt=0;
int num[300500];
struct node{
    int f=0;
    node* next[2];
};
node* head;
void insert(int num,int n) {
    node*t=head;
    stack<int>s;
    while(num){
        s.push(num%2);
        num/=2;
    }
    while(s.size()!=tt){
        s.push(0);
    }
    while(!s.empty()){
        int x=s.top();
        s.pop();
        if(t->next[x]==NULL){
            node*tt=new node();
            t->next[x]=tt;
        }
        t=t->next[x];
    }
    t->f=n;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    int q;
    cin>>q;
    head=new node();
    for(int i=0;i<n;i++){
        cin>>num[i];
        tt=max(tt,(int)log2(num[i])+1);
    }
    for(int i=0;i<n;i++){
        insert(num[i],i);
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int t=a;
        int l,r;
        stack<int>s;
        while(t){
            s.push(t%2);
            t/=2;
        }
        while(s.size()<tt){
            s.push(0);
        }
        while(s.size()>tt){
            s.pop();
        }
        int maxs=0;
        node*ttt=head;
        int now=tt;
        while(!s.empty()){
            int x=s.top();
            s.pop();
            if(ttt->next[!x]==NULL){
                ttt=ttt->next[x];
                now--;
                continue;
            }
            maxs+=pow(2,now-1);
            now--;
            ttt=ttt->next[!x];
        }
        l=ttt->f;
        t=a;
        s=stack<int>();
        while(t){
            s.push(t%2);
            t/=2;
        }
        while(s.size()<tt){
            s.push(0);
        }
        while(s.size()>tt){
            s.pop();
        }
        int mins=0;
        ttt=head;
        now=tt;
        while(!s.empty()){
            int x=s.top();
            s.pop();
            if(ttt->next[x]==NULL){
                ttt=ttt->next[!x];
                mins+=pow(2,now-1);
                now--;
                continue;
            }
            now--;
            ttt=ttt->next[x];
        }
        r=ttt->f;
        if((maxs-b)*(mins-b)<0){
            if(l>r){
                swap(l,r);
            }
            while(l!=r){
                int mid=(l+r)/2;
                if(((a^num[mid])-b)*((num[r]^a)-b)<=0){
                    l=mid;
                } else {
                    r=mid;
                }
            }
            cout<<l+1<<'\n';
        } else {
            cout<<-1<<'\n';
        }
    }
    return 0;
}