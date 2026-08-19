class TreeAncestor {
public:
    vector<vector<int>> father;
    TreeAncestor(int n, vector<int>& parent) {
        father.resize(n,vector<int>(20,-1));
        for(int i=0;i<n;i++)
            father[i][0]=parent[i];
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                if(father[j][i-1]!=-1){
                    father[j][i]=father[father[j][i-1]][i-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){
            if(k&(1<<i))
                node=father[node][i];
            if(node==-1){
                break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */