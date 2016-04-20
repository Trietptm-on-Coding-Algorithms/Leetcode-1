class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0) {
            return false;
        } else {
            int count = 0;
            for (int i = 0; i < 16; ++i, num >>= 2) {
                if ((num & 3) == 1) {
                    ++count;
                } else if ((num & 3) != 0) {
                    return false;
                }
            }
            
            return count == 1;
        }
    }
};