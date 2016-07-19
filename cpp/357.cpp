class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }

    vector<int> cur(n + 1, 0)
    vector<int> results(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        results[i] = 10;
        cur[i] = 9;
      } else if (i <= 10) {
        cur[i] = cur[i - 1] * (11 - i);
        results[i] = cur[i] + results[i - 1];
      } else {
        results[i] = results[i - 1];
      }
    }
    
    return results.back();
  }
}
