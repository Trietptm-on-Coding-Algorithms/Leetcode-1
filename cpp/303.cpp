class NumArray {
public:
    NumArray(vector<int> &nums) {
        for (auto num : nums) {
            if (sums.empty()) {
                sums.push_back(num);
            } else {
                sums.push_back(sums.back() + num);
            }
        }
    }

    int sumRange(int i, int j) {
        if (sums.empty())
            return 0;
        else
            return sums[max(i, 0)] - 
                        sums[min(j, sums.size() - 1)];
    }

private:
    vector<int> sums;
};
