class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long ans = 0, mod = 1e9 + 7;
        int n = arr.size();
        for(int i=0;i<=n;i++) {
            while(!st.empty() && (i==n || arr[st.top()] > arr[i])) {
                int curr = st.top();
                st.pop();
                if(st.empty()) {
                    ans = (ans%mod + ((arr[curr]%mod * (curr - (-1)))%mod * (i - curr))%mod)%mod;
                }
                else {
                    ans = (ans%mod + ((arr[curr]%mod *(curr - st.top()))%mod * (i - curr))%mod)%mod;
                }
            }
            st.push(i);
            
        }
        return ans;
    }
};