class Solution {
public:
    string removeDuplicateLetters(string s) {
        int ahead[256] = {};
        for (char c : s)
            ahead[c]++;

        string result = " ";
        bool inresult[256] = {};

        for (char c : s) {
            ahead[c]--;
            if (inresult[c])
                continue;
            while (c < result.back() && ahead[result.back()]) {
                inresult[result.back()] = false;
                result.pop_back();
            }
            result += c;
            inresult[c] = true;
        }

        return result.substr(1);
    }
};
