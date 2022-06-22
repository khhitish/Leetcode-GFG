class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int ans =20000;
            int i=0;
            while(i<n-2)
            {
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    //cout<<sum<<endl;
                    if (abs(target - sum) < abs(target - ans))
                    {
                        ans = sum;
                    }
                    if (sum > target) k--;
                    else if (sum < target) j++;
                    else return ans;
                }
                int t = nums[i];
                while (i < n - 2 && nums[i] == t) i++; // skipping the duplicates
            }
            return ans;
        }
};