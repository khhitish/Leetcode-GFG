class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto&x : asteroids) {
            if(x > 0) {
                ans.push_back(x);
            }
            else {
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(x)) {
                    ans.pop_back();
                }
                if(ans.empty() || ans.back() < 0) {
                    ans.push_back(x);
                }
                else {
                    if(ans.back() == abs(x))ans.pop_back();
                }
            }
        }
        return ans;
    }
};