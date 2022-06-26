class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum = 0, ans=0;
        for(int i=0;i<k;i++) sum+=nums[i];
        ans=max(ans,sum);
        int i=k,j=nums.size();
        while(i>0)
        {
            i--;j--;
            sum-=nums[i];
            sum+=nums[j];
            ans=max(ans,sum);
        }
        return ans;
    }
};