class Solution {
    // https://youtu.be/wT7gcXLYoao
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans;
        k--;
        for(int i=0;i<n;i++)
        {
            int temp = k/fact;
            ans+=('0' + nums[temp]);
            nums.erase(nums.begin() + temp);
            k = k%fact;
            if(nums.size()==0) break;
            fact/=nums.size();
        }
        return ans;
    }
};