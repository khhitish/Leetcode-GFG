class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128,0);
        for(auto&x : t) {
            freq[x]++;
        }
        int counter = t.size(), left = 0, right = 0, n = s.size();
        int start = 0, len = n+1;
        while(right < n) {
            if(freq[s[right]] > 0) {
                counter--;
            }
            freq[s[right]]--;
            // cout<<left<<" "<<right<<" "<<counter<<endl;
            while(counter == 0) {
                if(right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }
                if(freq[s[left]]>=0) counter++;
                freq[s[left]]++;
                left++;
            }
            right++;
        }
        if(len == n+1) return "";
        return s.substr(start,len);
    }
};