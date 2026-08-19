class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> vals;
        vector<int> ans;
        for(int i=0;i<n;i++){
            vals.push_back({nums[i],i});
        }
        sort(vals.begin(),vals.end());
        int r=n-1;
        for(int i=0;i<n;i++){
            while(r>i&&vals[i].first+vals[r].first>target){
                 r--;
            }
            if(vals[i].first+vals[r].first==target){
                ans.push_back(vals[i].second);
                ans.push_back(vals[r].second);
                break;
            }
        }
        return ans;
    };
};