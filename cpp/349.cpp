class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        
        vector<int> result;
        for (auto& num : nums2) {
            if (n1.count(num)) {
                result.push_back(num);
                n1.erase(num);
            }
        }
        
        return result;
    }
};