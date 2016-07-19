int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int left = 1, right = n, mid, result;

		while (left <= right) {
			mid = left + (right - left) / 2;
			result = guess(mid);
			if (result == 0) {
				return mid;
			} else if (result == -1) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
	}
}
