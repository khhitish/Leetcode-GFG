class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> mpp;
        for(auto&x : changed)
        {
            mpp[x]++;
        }
        //cout<<mpp[0]<<endl;
        vector<int> ans;
        for(auto& it : mpp)
        {
            int num = it.first;
            //cout<<num<<endl;
            if(num==0)
            {
                if(it.second % 2 !=0) return {};
                for(int i=0;i<it.second/2;i++)
                {
                    ans.push_back(num);
                }
            }
            else
            {
                if(mpp[num*2]<mpp[num]) return {};
                mpp[num*2]-=mpp[num];
                if(mpp[num*2]==0)mpp.erase(num*2);
                for(int i=0;i<it.second;i++)
                {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};