#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(2*n,vector<int>(2*n));
    for(int i=0;i<n*2;i++){
        string s;
        cin>>s;
        for(int j=0;j<n*2;j++){
            a[i][j]=(s[j]=='X'?1:0);
        }
    }
    auto b=a;
    auto rotate=[&](int i){
        int val=b[i][i];
        for(int j=i;j<2*n-i-1;j++){
            b[j][i]=b[j+1][i];
        }
        for(int j=i;j<2*n-i-1;j++){
            b[2*n-i-1][j]=b[2*n-i-1][j+1];
        }
        for(int j=2*n-i-1;j>i;j--){
            b[j][2*n-i-1]=b[j-1][2*n-i-1];
        }
        for(int j=2*n-i-1;j>i;j--){
            b[i][j]=b[i][j-1];
        }
        b[i][i+1]=val;
    };
    auto subrec=[&](vector<vector<int>> &rec,int i){
        vector<int> val;
        for(int j=i;j<2*n-i-1;j++)
            val.push_back(rec[j][i]);
        for(int j=i;j<2*n-i-1;j++){
            val.push_back(rec[2*n-i-1][j]);
        }
        for(int j=2*n-i-1;j>i;j--){
            val.push_back(rec[j][2*n-i-1]);    
        }
        for(int j=2*n-i-1;j>i;j--){
            val.push_back(rec[i][j]);
        }
        return val;
    };
    vector<vector<int>> goal(2*n,vector<int>(2*n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            goal[i][j]=1;
    int sum=0,ans=1e9;
    for(int i=n-1;i>=0;i--){
        auto sub_goal=subrec(goal,i);
        while(sub_goal!=subrec(b,i)){
            rotate(i);
            sum++;
        }
    }
    ans=min(ans,sum);
    b=a;
    sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            goal[i][j]=0;
    for(int i=0;i<n;i++)
        for(int j=n;j<n*2;j++)
            goal[i][j]=1;
    for(int i=n-1;i>=0;i--){
        while(subrec(goal,i)!=subrec(b,i)){
            rotate(i);
            sum++;
        }
    }
    ans=min(ans,sum);
    b=a;
    sum=0;
    for(int i=0;i<n;i++)
        for(int j=n;j<n*2;j++)
            goal[i][j]=0;
    for(int i=n;i<n*2;i++)
        for(int j=0;j<n;j++)
            goal[i][j]=1;
    for(int i=n-1;i>=0;i--){
        while(subrec(goal,i)!=subrec(b,i)){
            rotate(i);
            sum++;
        }
    }
    ans=min(ans,sum);
    b=a;
    sum=0;
    for(int i=n;i<n*2;i++)
        for(int j=0;j<n;j++)
            goal[i][j]=0;
    for(int i=n;i<n*2;i++)
        for(int j=n;j<n*2;j++)
            goal[i][j]=1;
    for(int i=n-1;i>=0;i--){
        while(subrec(goal,i)!=subrec(b,i)){
            rotate(i);
            sum++;
        }
    }
    ans=min(ans,sum);
    cout<<ans<<endl;
    return 0;
}