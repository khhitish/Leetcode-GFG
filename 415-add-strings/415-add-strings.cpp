class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        string ans;
        int i=num1.size()-1, j=num2.size()-1;
        while(i>=0 && j>=0)
        {
            int n1 = num1[i]-'0';
            int n2 = num2[j] - '0';
            int sum = (n1 + n2 + carry)%10;
            ans+=(sum+'0');
            carry = (n1+n2+carry)/10;
            i--;j--;
        }
        while(i>=0)
        {
            int sum = (num1[i]-'0' + carry)%10;
            ans+=(sum + '0');
            carry = (num1[i]-'0' + carry)/10;
            i--;
        }
        while(j>=0)
        {
            int sum = (num2[j]-'0' + carry)%10;
            ans+=(sum + '0');
            carry = (num2[j]-'0' + carry)/10;
            j--;
        }
        if(carry>0)
        {
            ans+=(carry + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};