class NumArray {
private:
    vector<int> segtree;
    int n;
    
    int buildtree(int left, int right, int node, vector<int>& nums)
    {
        if(left == right)
        {
            segtree[node] = nums[left];
            return segtree[node];
        }
        int mid = left + (right - left)/2;
        int leftsum = buildtree(left,mid,2*node + 1, nums);
        int rightsum = buildtree(mid+1,right,2*node+2,nums);
        segtree[node] = leftsum + rightsum;
        return segtree[node];
    }
    
    int suminrange(int left, int right, int ss, int se, int node)
    {
        if(right<ss || left>se) return 0;
        if(left<=ss && right>=se) return segtree[node];
        int mid = ss + (se - ss)/2;
        int leftsum = suminrange(left,right,ss,mid,2*node+1);
        int rightsum = suminrange(left,right,mid+1,se,2*node+2);
        return leftsum + rightsum;
    }
    
    int updateseg(int ss, int se, int ind, int newval, int node)
    {
        if(ind < ss || ind > se) return segtree[node];
        if(ss==se)
        {
            segtree[node] = newval;
            return segtree[node];
        }
        int mid = ss + (se-ss)/2;
        int leftsum = updateseg(ss,mid,ind,newval,2*node+1);
        int rightsum = updateseg(mid+1,se,ind,newval,2*node+2);
        segtree[node] = leftsum + rightsum;
        return segtree[node];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n);
        buildtree(0,n-1,0,nums);
    }
    
    void update(int index, int val) {
        updateseg(0,n-1,index,val,0);
    }
    
    int sumRange(int left, int right) {
        return suminrange(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */