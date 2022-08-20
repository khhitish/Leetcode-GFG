class NumArray {
private:
    vector<int> pref;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pref.resize(n,0);
        for(int i=0;i<n;i++)
        {
            pref[i] = nums[i];
            if(i-1>=0) pref[i]+=pref[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        int ans = pref[right];
        if(left-1>=0) ans-=pref[left-1];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */