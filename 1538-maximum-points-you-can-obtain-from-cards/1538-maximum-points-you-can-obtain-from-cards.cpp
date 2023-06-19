class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        // // Minimum subarray sum of size n-k
        // int n = nums.size();
        // int fullSum = 0;
        // for(auto &x : nums) fullSum += x;
        // int sz = n-k;
        // if(sz == 0) return fullSum;
        // int currSum = 0, minSum = INT_MAX;
        // for(int i=0;i<n;i++) {
        //     currSum+=nums[i];
        //     if(i == sz-1) {
        //         minSum = min(minSum, currSum);
        //     }
        //     if(i >= sz) {
        //         currSum -= nums[i-sz];
        //         minSum = min(minSum, currSum);
        //     }
        // }
        // return fullSum - minSum;

        // Direct implementation of the question
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