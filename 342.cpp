class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        } else {
            //test even bit if is zero(start from 1)
            int even = 0xaaaaaaaa;
            int odd = 0x55555555;
            
            if ((even & num) == 0 && (odd & (num << 1)) == 0)
                return true;
            
            return false;
        }
    }
};