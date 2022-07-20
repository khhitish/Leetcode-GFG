class Solution {
private:
    int helper(vector<string>& arr, int index, string s)
    {
        unordered_set st(s.begin(), s.end());
        if(st.size()<s.size()) return 0;
        int ans=s.size();
        for(int i=index;i<arr.size();i++)
        {
            ans=max(ans, helper(arr,i,s+arr[i]));
        }
        return ans;
    }
public:
    int maxLength(vector<string>& arr) {
        return helper(arr,0,"");
    }
};