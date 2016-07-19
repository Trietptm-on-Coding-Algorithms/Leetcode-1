class Solution {
    struct {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            if (lhs.second == rhs.second)   
                return lhs.first < rhs.first;
            
            return lhs.second >= rhs.second;
        }   
    } greater;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tables;
        
        for (auto& num : nums) {
            if (tables.find(num) == tables.end()) {
                tables[num] = 1;
            } else {
                ++tables[num];
            }
        }
        
        vector<pair<int, int>> tmp;
        for (auto& item : tables) {
           tmp.push_back(item);
        }
        
        sort(tmp.begin(), tmp.end(), greater);
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(tmp[i].first);
        }
        
        return result;
    }    
};