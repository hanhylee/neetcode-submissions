class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int max_profit = 0;

        for (int i=0; i<prices.size(); i++) {
            for (int j=i+1; j<prices.size(); j++) {
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }

        return max_profit;
    }
};
