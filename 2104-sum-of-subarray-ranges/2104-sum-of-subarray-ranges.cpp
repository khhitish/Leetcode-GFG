class Solution {
    // https://leetcode.com/problems/sum-of-subarray-minimums/
    
    // https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step //see the end and comments or replies
    
    //https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1626628/O(n)-solution-with-monotonous-stack-oror-Full-explaination
public:
    long long subArrayRanges(vector<int>& arr) {
        stack<long long> s;
        long long ans=0;
        int n=arr.size();
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n || arr[s.top()]<arr[i]))//i==n added to avoid writing another while loop
            {
                long long temp=s.top();
                s.pop();
                if(s.empty())
                {
                    ans+=arr[temp]*(temp-(-1))*(i-temp);
                    continue;
                }
                ans+=arr[temp] * (temp-s.top()) *(i-temp);
            }
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n || arr[s.top()]>arr[i]))//i==n added to avoid writing another while loop
            {
                long long temp=s.top();
                s.pop();
                if(s.empty())
                {
                    ans-=arr[temp]*(temp-(-1))*(i-temp);
                    continue;
                }
                ans-=arr[temp] * (temp-s.top()) *(i-temp);
            }
            s.push(i);
        }
        return ans;
    }
};