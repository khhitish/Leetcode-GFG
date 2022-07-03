class Solution {
// https://youtu.be/AoX3BPWNnoE
public:
    int majorityElement(vector<int>& nums) {
        int count=0, element=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0) element=nums[i];
            if(nums[i]==element)count++;
            else count--;
        }
        return element;
    }
};