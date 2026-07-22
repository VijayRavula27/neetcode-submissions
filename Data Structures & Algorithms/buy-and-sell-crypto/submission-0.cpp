class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Buyprice = prices[0];
        int maxprofit = 0;

        for(int i = 0; i < prices.size(); i++){
            if(Buyprice > prices[i])
           Buyprice = prices[i];
           maxprofit = max(maxprofit, prices[i] - Buyprice);
        }
        return maxprofit;
    }
};
