class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
            return false;

        string tmp(preorder.rbegin(), preorder.rend());
        stringstream rev(tmp);
        stack<char> leaves;

        for (string word; getline(rev, word, ','); nullptr) {
            if (word == "#") {
                leaves.push('#');
            } else if (leaves.size() < 2){
                return false;
            } else {
                leaves.pop();
            }
        }

        return 1 == leaves.size();
    }
};