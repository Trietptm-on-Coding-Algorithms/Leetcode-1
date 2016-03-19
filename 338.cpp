class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        
        for (int i = 1, next = 1, pre = 0; i <= num; ++i) {
            if (i == next) {
                result[i] = 1;
                pre = next;
                next += next;
            } else {
                result[i] = result[pre] + result[i-pre];
            }
        }
        
        return result;
    }
};