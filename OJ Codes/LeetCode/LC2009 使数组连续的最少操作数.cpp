class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int m=unique(nums.begin(),nums.end())-nums.begin();
        int r=0,ans=n;
        for(int l=0;l<m;l++){
            while(r+1<m&&nums[r+1]-nums[l]<=n-1){
                r++;
            }
            ans=min(ans,n-(r-l+1));
        }
        return ans;
    }
};