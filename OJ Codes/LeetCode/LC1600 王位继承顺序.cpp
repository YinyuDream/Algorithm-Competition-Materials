class ThroneInheritance {
public:
    string kingName;
    map<string,vector<string>> G;
    map<string,int> ban;
    ThroneInheritance(string kingName) {
        this->kingName = kingName;
        G[kingName] = vector<string>();
        ban[kingName] = 0;
    }
    
    void birth(string parentName, string childName) {
        G[parentName].push_back(childName);
        ban[childName] = 0;
    }
    
    void death(string name) {
        ban[name] = 1;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        function<void(string)> dfs=[&](string u){
            if(!ban[u]){
                ans.push_back(u);
            }
            for(auto v:G[u]){
                dfs(v);
            }
        };
        dfs(kingName);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */