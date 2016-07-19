class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN), preSell(0), sell(0), preBuy(0);

        for (int price : prices) {
            preBuy = buy;
            buy = max(preSell - price, buy);
            preSell = sell;
            sell = max(preBuy + price, sell);
        }

        return sell;
    }
};
