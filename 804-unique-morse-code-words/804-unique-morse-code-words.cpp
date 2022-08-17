class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mappings = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto&x : words)
        {
            string temp;
            for(auto&c : x)
            {
                temp+=mappings[c-'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};