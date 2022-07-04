class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++)
        {
            m[nums1[i]]=i;
        }
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums2[i])
            {
                s.pop();
            }
            if(m.count(nums2[i])!=0)
            {
                if(s.empty())ans[m[nums2[i]]]=-1;
                else ans[m[nums2[i]]]=s.top();
            }
            s.push(nums2[i]);
        }
        return ans;
    }
};