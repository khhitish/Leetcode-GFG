class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i=0;i<=n;i++) {
            while(!st.empty() && (i == n || heights[st.top()] > heights[i])) {
                int curr = st.top();
                st.pop();
                int temp;
                if(st.empty()) {
                    temp = heights[curr] * (i - (-1) - 1);
                }
                else {
                    temp = heights[curr] * (i - st.top() - 1);
                }
                ans = max(ans,temp);
            }
            st.push(i);
        }
        return ans;
    }
};