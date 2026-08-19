#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3],n;
    cin>>a[0]>>a[1]>>a[2]>>n;
    int mn=*min_element(a,a+3);
    int mx=*max_element(a,a+3);
    int sum=a[0]+a[1]+a[2];
    int mid=sum-mn-mx;
    if(sum-2*mn>n){
        cout<<"NO";
        return 0;
    }
    string ans[3];
    for(int i=0;i<mn;i++){
        ans[0].push_back('a');
        ans[1].push_back('a');
        ans[2].push_back('a');
    }
    for(int i=0;i<mid-mn;i++){
        ans[0].push_back('w');
        ans[1].push_back('b');
        ans[2].push_back('b');
    }
    for(int i=0;i<mx-mn;i++){
        ans[0].push_back('c');
        ans[1].push_back('c');
        ans[2].push_back('f');
    }
    int sz=ans[0].size();
    for(int i=0;i<n-sz;i++){
        ans[0].push_back('x');
        ans[1].push_back('y');
        ans[2].push_back('z');
    }
    auto LCS=[&](string &u,string &v){
        vector<vector<int>> dp(u.size()+1,vector<int>(v.size()+1));
        for(int i=1;i<=u.size();i++){
            for(int j=1;j<=v.size();j++){
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(u[i-1]==v[i-1]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        return dp[u.size()][v.size()];
    };
    vector<int> ord(3);
    iota(ord.begin(),ord.end(),0);
    do{
        string &s1=ans[ord[0]];
        string &s2=ans[ord[1]];
        string &s3=ans[ord[2]];
        if(LCS(s1,s2)==a[0]&&LCS(s2,s3)==a[1]&&LCS(s1,s3)==a[2]){
            cout<<s1<<endl<<s2<<endl<<s3<<endl;
            return 0;
        }
    }while(next_permutation(ord.begin(),ord.end()));
    return 0;
}