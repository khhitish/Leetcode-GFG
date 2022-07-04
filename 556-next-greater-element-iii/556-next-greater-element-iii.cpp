class Solution {
public:
    int nextGreaterElement(int n) {
        string res=to_string(n);
        next_permutation(res.begin(), res.end());
        long long ans = stoll(res);
        if(ans > INT_MAX || ans <= n) return -1;
        return ans;
    }
};