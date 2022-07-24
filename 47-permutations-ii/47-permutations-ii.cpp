class Solution {
private:
    void permute(int i, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int j=i;j<nums.size();j++)
        {
            if(st.count(nums[j])!=0) continue;
            st.insert(nums[j]);
            swap(nums[i], nums[j]);
            permute(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(0,nums,ans);
        return ans;
    }
};