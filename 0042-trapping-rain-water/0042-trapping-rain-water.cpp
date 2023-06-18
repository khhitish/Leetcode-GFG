class Solution {
public:
    int trap(vector<int>& height) {
        // most optimal, two pointers, O(n) time, O(1) space
        int left = 0, right = height.size()-1;
        int leftmax = 0, rightmax = 0;
        int ans = 0;
        while(left<=right) {
            if(height[left] <= height[right]) {
                leftmax = max(leftmax,height[left]);
                ans += (leftmax - height[left]);
                left++;
            }
            else {
                rightmax = max(rightmax,height[right]);
                ans += (rightmax - height[right]);
                right--;
            }
        }
        return ans;
    }
};