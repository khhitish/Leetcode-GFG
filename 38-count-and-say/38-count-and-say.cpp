class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string t1 = countAndSay(n-1);
        int i=0, m=t1.size();
        string ans;
        while(i<m)
        {
            char temp = t1[i];
            int count=0;
            while(i<m && t1[i]==temp)
            {
                count++;i++;
            }
            ans+=to_string(count);
            ans+=temp;
        }
        return ans;
    }
};