class Solution {
private:
    bool ispossible(vector<int>& nums, int currsum, int target, int k, int start, vector<int>& vis)
    {
        if(k==1) return true;
        if(start>=nums.size()) return false;
        if(currsum==target)
        {
            return ispossible(nums,0,target,k-1,0,vis);
        }
        for(int i=start;i<nums.size();i++)
        {
            if(!vis[i] && nums[i] + currsum <= target)
            {
                vis[i]=1;
                if(ispossible(nums,currsum+nums[i],target,k,i+1,vis)) return true;
                vis[i]=0;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return false;
        int target=sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> vis(nums.size(),0);
        return ispossible(nums,0,target,k,0,vis);
    }
};