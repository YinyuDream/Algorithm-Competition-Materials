class Solution {
public:
    int query(vector<vector<int>> &st, int l, int r){
        int val=log2(r-l+1);
        return max(st[l][val],st[r-(1<<val)+1][val]);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        vector<vector<int>> st(n,vector<int>(17));
        for(int i=0;i<n;i++)
            st[i][0]=heights[i];
        for(int j=1;j<=16;j++)
            for(int i=0;i+(1<<j)-1<n;i++)
                st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        vector<int> ans;
        for(auto q:queries){
            int u=q[0],v=q[1];
            if(u>v)swap(u,v);
            if(heights[u]<heights[v]){
                ans.push_back(v);
                continue;
            }
            if(u==v){
                ans.push_back(v);
                continue;
            }
            int mx=max(heights[u],heights[v]);
            int l=v+1,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(query(st,v+1,mid)<=mx){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            ans.push_back(l<n?l:-1);
        }
        return ans;
    }
};