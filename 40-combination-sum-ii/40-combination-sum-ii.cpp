class Solution {
    // here instead of deciding whether to take the current value or not take the current value into our subset, we are deciding which number to take for a particular position of the subset
private:
    // https://youtu.be/G1fRTGRxXU8
    void helper(int i, int target, vector<int> &c, vector<int>& temp, vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<c.size();j++)
        {
            if(j>i && c[j-1]==c[j]) continue;
            if(c[j]>target) break;
            temp.push_back(c[j]);
            helper(j+1,target-c[j],c,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(c.begin(), c.end());
        helper(0,target,c,temp,ans);
        return ans;
    }
};