class Solution {
public:
    string getHint(string secret, string guess) {
        ostringstream result;

        if (secret.size() != guess.size() || secret.empty())
            return result.str();

        vector<int> table(10, 0);
        const int size = secret.size();
        int bulls = 0, cows = 0;

        for (int idx = 0; idx < size; ++idx) {
            int sec = secret[idx] - '0', gue = guess[idx] - '0';

            if (sec == gue) {
                ++bulls;
            } else {
                if (table[sec] < 0)
                    ++cows;

                if (table[gue] > 0)
                    ++cows;

                ++table[sec];
                --table[gue];
            }
        }

        result << bulls << "A" << cows << "B"; 
        return result.str();
    }
};