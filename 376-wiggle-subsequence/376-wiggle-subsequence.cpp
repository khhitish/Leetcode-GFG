class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> up(n), down(n);
        up[0]=down[0]=1;
        int uplast=1,downlast=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                // up[i]=down[i-1]+1;
                // down[i]=down[i-1];
                uplast=downlast+1;
                downlast=downlast;
            }
            else if(nums[i]<nums[i-1])
            {
                // up[i]=up[i-1];
                // down[i] = up[i-1]+1;
                uplast=uplast;
                downlast=uplast+1;
            }
            else
            {
                // down[i]=down[i-1];
                // up[i]=up[i-1];
                uplast=uplast;
                downlast=downlast;
            }
        }
        // return max(up[n-1],down[n-1]);
        return max(uplast,downlast);
    }
};