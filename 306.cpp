class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
            return false;

        int half = num.size() >> 1;
        for (int idx = 0; idx < half; ++idx) {
            long long cur = stoll(num.substr(0, idx + 1));
            if (help(num.substr(idx + 1), cur))
                return true;
        }

        return false;
    }

private:
    bool help(string num, long long pre) {
        if (num.empty())
            return true;

        int half = num.size() >> 1;
        for (int idx = 0; idx < half; ++idx) {
            long long cur = stoll(num.substr(0, idx + 1));
            string now = to_string(pre + cur);

            if (now == num.substr(idx + 1)) {
                return true;
            } else if (now.size() < num.size()-idx-1) {
                int match = 0;
                while (match < now.size()) {
                    if (now[match] == num[idx + 1 + match]) {
                        ++match;
                    } else {
                        break;
                    }
                }

                if (match == now.size() &&
                    help(num.substr(idx + 1), cur)) {
                    return true;
                }
            }
        }

        return false;
    }
};