#include<bits/stdc++.h>
using namespace std;
int n,m;
set<vector<int> >st,tp;
vector<int>vc;
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        int num;
        cin>>num;
        vc.push_back(num);
    }
    st.insert(vc);
    
    for(int i=2;i<=n;i++){
        vc.clear();
        while(!tp.empty())
            tp.clear();
        for(int j=1;j<=m;j++){
            int num;
            cin>>num;
            vc.push_back(num);
        }
        tp.insert(vc);
        for(auto j:st){
            vector<int>new_vec;
            for(auto k:vc)
                new_vec.push_back(j[k-1]);
            tp.insert(new_vec);
        }
        st.insert(tp.begin(),tp.end());
    }
    cout<<st.size()<<endl;
    return 0;
}