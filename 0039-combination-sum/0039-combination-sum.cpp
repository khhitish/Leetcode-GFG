class Solution {
private:
    void helper(int i, vector<int>& temp, vector<vector<int>>& ans, vector<int>& c, int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(i>=c.size()) return;
        if(c[i]<=target)
        {
            temp.push_back(c[i]);
            helper(i,temp,ans,c,target-c[i]);
            temp.pop_back();
        }
        helper(i+1,temp,ans,c,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0,temp,ans,candidates,target);
        return ans;
        
        
    }
};