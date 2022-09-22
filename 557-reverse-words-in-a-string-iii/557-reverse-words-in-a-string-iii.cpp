class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0,j=0;
        while(j<n){
            while(j<n && s[j]!=' ')j++;
            reverse(s.begin() + i, s.begin()+j);
            j++;
            i=j;
        }
        return s;
    }
};