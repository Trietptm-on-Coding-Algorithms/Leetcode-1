class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        int size = coins.size();
        sort(coins.begin(), coins.end());

        vector<int> tables(amount + 1, -1);

        for (int idx = 1; idx < amount + 1; ++idx) {
            for (int now = 0; now < size && idx - coins[now] >= 0; ++now){
                    if (idx - coins[now] == 0) {
                        tables[idx] = 1;
                    } else if (tables[idx - coins[now]] != -1) {
                        if (tables[idx] == -1)
                            tables[idx] = 1 + tables[idx - coins[now]];
                        else
                            tables[idx] =
                        min(tables[idx], 1 + tables[idx - coins[now]]);
                    }
            }
        }

        return tables.back();
    }
};
