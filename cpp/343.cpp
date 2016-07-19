class Solution {
public:
    int integerBreak(int n) {
        
        if (n < 4) {
            return n - 1; 
        } else if (n == 4) {
            return n;
        } else {
            int result = 1;
            while(n > 4) {
                result *= 3;
                n -= 3;
            }
            
            return result * n;
        }
    }
};