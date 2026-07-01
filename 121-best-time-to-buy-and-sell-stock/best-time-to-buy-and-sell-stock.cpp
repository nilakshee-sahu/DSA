class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // calculate best buying price for each price
        vector<int> bestBuy(n);
        bestBuy[0] = prices[0];;
        for(int i=1; i<n; i++){
            bestBuy[i] = min(prices[i], bestBuy[i-1]);
        }
        
        // calculate profit for each price 
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            int profit = prices[i] - bestBuy[i];
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};