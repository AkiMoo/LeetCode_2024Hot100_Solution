class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n);
        vector<int> sell(n);
        buy[0] = -prices[0];
        for(int i=1;i<n;i++){
            buy[i] = max(-prices[i],buy[i-1]);
            sell[i] = prices[i] + buy[i];
        }
        return *max_element(sell.begin(),sell.end());
    }
};
