class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> mpp;
        for(auto&x : arr)
        {
            mpp[x]++;
        }
        for(auto& it : mpp)
        {
            int num = it.first;
            if(num==0)
            {
                if(it.second%2==1) return false;
            }
            else if(num>0)
            {
                if(mpp[num*2]<mpp[num]) return false;
                mpp[num*2]-=mpp[num];
                if(mpp[num*2]==0) mpp.erase(num*2);
            }
            else
            {
                if(num%2!=0) return false;
                if(mpp[num/2]<mpp[num]) return false;
                mpp[num/2]-=mpp[num];
                if(mpp[num/2]==0) mpp.erase(num/2);
            }
        }
        return true;
    }
};