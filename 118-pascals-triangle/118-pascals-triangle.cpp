class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> prev = {1};
        ans.push_back(prev);
        for(int i = 1;i < n; i++)
        {
            vector<int> temp(i+1);
            temp[0] = temp[i]=1;
            for(int j = 1;j<i;j++)
            {
                temp[j] = prev[j-1] + prev[j];
            }
            prev=temp;
            ans.push_back(prev);
        }
        return ans;
    }
};