#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> earliest_male(N+1,INT_MAX);
    vector<string> results;
    for(int i=0;i<M;i++){
        int family_id;
        char gender;
        cin>>family_id>>gender;
        if(gender == 'M'){
            if(earliest_male[family_id]==INT_MAX){
                earliest_male[family_id]=i;
            }
        }
        if(earliest_male[family_id]==i){
            results.push_back("Yes");
        }else{
            results.push_back("No");
        }
    }
    for (const auto& result:results) {
        cout<<result<<endl;
    }
    return 0;
}