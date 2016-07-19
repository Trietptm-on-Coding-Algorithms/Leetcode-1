class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> idxs(k, 0), uglys(n, INT_MAX);
        uglys[0] = 1;

        for (int nth = 1; nth < n; ++nth) {
            for (int idx = 0; idx < k; ++idx) {
                uglys[nth] = min(
                    uglys[nth], primes[idx] * uglys[idxs[idx]]);
            }

            for (int idx = 0; idx < k; ++idx) {
                idxs[idx] +=
                (uglys[nth] == primes[idx] * uglys[idxs[idx]]);
            }
        }

        return uglys.back();
    }
};
