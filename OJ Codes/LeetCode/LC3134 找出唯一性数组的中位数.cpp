class Solution {
private:
    int mx=0,n=0;
public:
    int count(vector<int>& nums, int val) {
        int r=0,tot=0;
        long long ans=0;
        vector<int> cnt(mx+1,0);
        cnt[nums[0]]=1;
        tot=1;
        for(int i=0;i<n;i++){
            while(r<n&&tot<=val){
                r++;
                if(r==n){
                    break;
                }
                cnt[nums[r]]++;
                if(cnt[nums[r]]==1){
                    tot++;
                }
            }
            ans+=r-i;
            cnt[nums[i]]--;
            if(!cnt[nums[i]]){
                tot--;
            }
        }
        long long seg=1ll*n*(n+1)/2;
        return ans<(seg+1)/2;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        mx=*max_element(nums.begin(),nums.end());
        n=nums.size();
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(count(nums,mid))l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};