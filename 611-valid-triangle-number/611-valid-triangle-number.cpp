class Solution {
public:
    // https://youtu.be/2e1LUkZoTiE
    // sort, fix right most number, apply two pointers on rest
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;
        for(int k = n-1;k>=2;k--)
        {
            int i=0, j=k-1;
            while(i<j)
            {
                if(nums[i] + nums[j] > nums[k])
                {
                    ans+=j-i;
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }
};