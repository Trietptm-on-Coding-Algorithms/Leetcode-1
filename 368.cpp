class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 0);
        vector<int> parent(dp);

        int maxLen = 0, indx = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;

                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        indx = i;
                    }
                }
            }
        }

        vector<int> results;
        for (int i = 0; i < maxLen; ++i) {
            results.push_back(nums[indx]);
            indx = parent[indx];
        }

        return results;
    }
};