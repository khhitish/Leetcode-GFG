class Solution {
public:
    bool canMeasureWater(int j1, int j2, int cap) {
        return  cap<=j1+j2 && cap % __gcd(j1,j2) == 0;
        
    }
};