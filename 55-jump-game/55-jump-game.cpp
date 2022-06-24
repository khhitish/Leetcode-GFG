class Solution {
    // https://youtu.be/C2SXPhEZ_38
public:
    bool canJump(vector<int>& nums) {
        int reachable=0, n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>reachable) return false;
            reachable=max(reachable, nums[i] + i);
        }
        return true;
    }
};