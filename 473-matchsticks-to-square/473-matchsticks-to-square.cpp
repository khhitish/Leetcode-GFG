class Solution {
private:
    bool helper(int i, int l1, int l2, int l3, int l4, vector<int>& nums, int maxlen)
    {
        if(i==nums.size())
        {
            if(l1==l2 && l2==l3 && l3==l4) return true;
            return false;
        }
        if(l1>maxlen || l2>maxlen || l3>maxlen || l4>maxlen) return false;
        bool opt1 = helper(i+1,l1+nums[i],l2,l3,l4,nums, maxlen);
        if(opt1==true) return true;
        bool opt2 = helper(i+1,l1,l2+nums[i],l3,l4,nums, maxlen);
        if(opt2==true) return true;
        bool opt3 = helper(i+1,l1,l2,l3+nums[i],l4,nums, maxlen);
        if(opt3==true) return true;
        bool opt4 = helper(i+1,l1,l2,l3,l4+nums[i],nums, maxlen);
        if(opt4==true) return true;
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int perimeter=accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(perimeter%4!=0) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int maxlen = perimeter/4;
        return helper(0,0,0,0,0,matchsticks,maxlen);
    }
};