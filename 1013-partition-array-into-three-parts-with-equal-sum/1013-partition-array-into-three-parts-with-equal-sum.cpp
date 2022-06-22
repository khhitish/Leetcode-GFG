class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%3!=0) return false;
        int req=sum/3;
        int currsum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            //cout<<currsum<<" ";
            if(currsum==req)
            {
                cnt++;
                currsum=0;
            }
            //else if(currsum>req) return false;
        }
        if(cnt>=3) return true;
        return false;
    }
};