class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());

        for (int i = nums.size() - 1, j = 0, k = i / 2 + 1;
            i >= 0;
            --i){
            nums[i] = copy[i & 1 ? k++ : j++]；
        }

        return ;
    }
};
