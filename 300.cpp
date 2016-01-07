class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        const int size = nums.size();
        vector<int> dp(size + 1, 1);
        int maxLen = 0;

        for (int idx = 0; idx < size; ++idx) {
            int curLen = 0;
            for (int pre = idx - 1; pre >= 0; --pre) {
                if (nums[pre] < nums[idx]) {
                    curLen = max(curLen, dp[pre]);
                }
            }

            dp[idx] += curLen;
            maxLen = max(maxLen, dp[idx]);
        }

        return maxLen;
    }
};