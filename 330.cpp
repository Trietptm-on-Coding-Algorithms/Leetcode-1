class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
            
        int patches = 0;
        long sum = 0;

        for (int want = 1, i = 0; sum < n; ++want) {
            if (i < nums.size() && want < nums[i]) {
                if (want > sum) {
                    ++patches;
                    sum += want;
                }
            } else {
                if (i < nums.size()) {
                    sum += nums[i++];
                } else {
                    if (want > sum) {
                        ++patches;
                        sum += want;
                    }
                }
            }
        }

        return patches;
    }
};