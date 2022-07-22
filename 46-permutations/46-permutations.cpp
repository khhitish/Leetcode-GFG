class Solution {
private:
    // void helperswap(int i, vector<int>& nums, vector<vector<int>>& ans)
    // {
    //     if(i==nums.size())
    //     {
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for(int j=i;j<nums.size();j++)
    //     {
    //         swap(nums[i], nums[j]);
    //         helperswap(i+1,nums,ans);
    //         swap(nums[i], nums[j]);
    //     }
    // }
    
    void helperset(int i,vector<int>& nums, vector<int>& vis, vector<int>& temp, vector<vector<int>>& ans)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(!vis[j])
            {
                temp.push_back(nums[j]);
                vis[j]=1;
                helperset(i+1,nums,vis,temp,ans);
                temp.pop_back();
                vis[j]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        //helperswap(0,nums,ans);
        
        vector<int> temp;
        vector<int> vis(nums.size(),0);
        helperset(0,nums,vis,temp,ans);
        return ans;
    }
};