class Solution {
private:
    void helper(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans)
    {
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            helper(j+1,nums,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(0,nums,temp,ans);
        return ans;
    }
};