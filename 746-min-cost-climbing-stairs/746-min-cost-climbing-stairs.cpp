class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2, prev1,n=cost.size();
        prev2=prev1=0;
        for(int i=2;i<=n;i++)
        {
            int s1=cost[i-1]+ prev1;
            int s2=cost[i-2] + prev2;
            int curr=min(s1, s2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};