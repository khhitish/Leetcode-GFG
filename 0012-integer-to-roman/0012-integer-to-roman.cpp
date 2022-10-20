class Solution {
public:
    string intToRoman(int num) {
        int number=num;
        string ans;
        vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;number>0;i++)
        {
            if(number>= val[i])
            {
                while(number>=val[i])
                {
                    ans+=roman[i];
                    number-=val[i];
                }
            }
        }
        return ans;
    }
};