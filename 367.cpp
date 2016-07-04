class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long left = 0, right = num; left <= right; ) {
            long long mid = (left + right) >> 1;
            long long square = mid * mid;

            if (square > num) {
                right = mid - 1;
            } else if (square < num) {
                left = mid + 1;
            } else {
                return true;
            }
        
        }

        return false;
    }
};