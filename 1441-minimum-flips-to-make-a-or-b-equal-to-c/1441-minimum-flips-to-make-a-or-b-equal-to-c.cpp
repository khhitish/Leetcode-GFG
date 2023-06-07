class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i=0;i<=30;i++) {
            int num = (1<<i);
            if((c & num) != 0) {
                if((a & num)!=0 || (b & num)!=0) continue;
                else ans++;
            }
            else {
                if((a & num)==0 && (b & num)==0) continue;
                else if((a & num)!=0 && (b & num)!=0)ans+=2;
                else ans++;
            }
        }
        return ans;
    }
};