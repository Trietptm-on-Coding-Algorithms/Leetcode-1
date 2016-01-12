class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0, product = 1;
        unordered_map<int, int> maxLen;

        for (string word : words) {
            int mask = 0;
            for (char alpha : word) {
                mask |= 1 << (alpha - 'a');
            }

            maxLen[mask] = static_cast<int>(word.size());
        }

        for (auto cur : maxLen) {
            for (auto next : maxLen) {
                if (!(cur.first & next.first)) {
                    result = max(result, cur.second * next.second);
                }
            }
        }

        return result;
    }
};
