class Solution {
private:
    bool compare(char a, char b) {
        if(a == '(' && b  == ')') return true;
        else if(a == '{' && b  == '}') return true;
        else if(a == '[' && b  == ']') return true;
        else return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto&x : s) {
            if(x == '(' || x =='{' || x=='[') {
                st.push(x);
            }
            else {
                if(st.empty() || !compare(st.top(), x)) return false;
                else st.pop();
            }
        }
        return st.size() == 0;
    }
};