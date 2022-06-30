class Solution {
public:
    // https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/1217473/C++PythonJava-2-Solutions-(w-and-wo-Median)-Explained-with-Example-implementation
    int minMoves2(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int ans=0;
        sort(nums.begin(), nums.end());
        while(left<right)
        {
            ans+=(nums[right]-nums[left]);
            left++; right--;
        }
        return ans;
    }
};