class Solution {
    // https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106514/C++Python-Esay-Understand-Solution
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> rem, end;
        for(auto&x : nums)rem[x]++;
        for(auto&x : nums)
        {
            if(rem[x]==0) continue;
            rem[x]--;
            if(end[x-1]>0)
            {
                end[x-1]--;
                end[x]++;
            }
            else if(rem[x+1]>0 && rem[x+2]>0)
            {
                rem[x+1]--;
                rem[x+2]--;
                end[x+2]++;
            }
            else return false;
        }
        return true;
    }
};