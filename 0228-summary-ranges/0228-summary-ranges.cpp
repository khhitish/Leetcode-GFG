class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        int start = nums[0], end = nums[0];
        vector<string> ans;
        for(int i=1;i<=n;i++) {
            if(i==n || nums[i]!=end+1) {
                string temp;
                temp = to_string(start);
                if(start != end) {
                    temp+="->";
                    temp+=to_string(end);
                }
                ans.push_back(temp);
                if(i<n) {
                    start = nums[i];
                    end = nums[i];
                }
            }
            else {
                end = nums[i];
            }
        }
        return ans;
    }
};