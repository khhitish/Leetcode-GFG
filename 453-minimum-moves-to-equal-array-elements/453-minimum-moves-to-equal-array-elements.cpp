class Solution {
public:
    // https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question
    int minMoves(vector<int>& nums) {
        int sum=0, mini=INT_MAX;
        for(auto&x : nums)
        {
            mini=min(mini,x);
            sum+=x;
        }
        int n=nums.size();
        return sum-mini*n;
    }
};