class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        vector<int> ans;
        for(auto&x : nums)
        {
            if(x%2==0)sum+=x;
            // cout<<x%2<<" ";
        }
        for(int i=0;i<queries.size();i++)
        {
            int ind = queries[i][1];
            int val = queries[i][0];
            if(nums[ind]%2==0)
            {
                if(abs(val)%2==0)
                {
                    nums[ind]+=val;
                    sum+=val;
                }
                else
                {
                    sum-=nums[ind];
                    nums[ind]+=val;
                }
            }
            else
            {
                if(abs(val)%2==1)
                {
                    nums[ind]+=val;
                    sum+=nums[ind];
                }
                else
                {
                    nums[ind]+=val;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};