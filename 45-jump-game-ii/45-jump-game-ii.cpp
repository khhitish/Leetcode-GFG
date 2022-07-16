class Solution {
    // https://youtu.be/wLPdkLM_BWo
public:
    int jump(vector<int>& nums) {
        int farthest=0, jumps=0,curr=0;
        int n=nums.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++)
        {
            
            farthest=max(farthest,i+nums[i]);
            if(i==curr)
            {
                jumps++;
                curr = farthest;
                if(curr>=n-1) return jumps;
            }
        }
        return jumps;
    }
};