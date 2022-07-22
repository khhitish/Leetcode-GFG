class Solution {
public:
    int minCost(string arr, vector<int>& cost) {
        int ans=0;
        int i=0, n=arr.size();
        while(i<n)
        {
            int j=i, sum=0, maxi=INT_MIN;
            while(j<n && arr[i]==arr[j])
            {
                sum+=cost[j];
                maxi=max(maxi,cost[j]);
                j++;
            }
            if(j-i>1)
            {
                ans+=(sum-maxi);
            }
            i=j;
        }
        return ans;
    }
};