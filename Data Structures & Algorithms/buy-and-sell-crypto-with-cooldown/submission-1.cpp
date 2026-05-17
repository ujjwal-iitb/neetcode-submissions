class Solution {
public:
    int findProfit(int curr, int mode, vector<int>& prices, vector<vector<int>>& dp){
        if(curr >= prices.size()){
            return 0;
        }
        if(dp[curr][mode]==-1){
            //if we have to buy
            if(mode==0){
                //possible profit
                int buy_now, buy_later;

                buy_now = -1*prices[curr] + findProfit(curr+1, 1, prices, dp);
                buy_later = findProfit(curr+1, 0, prices, dp);

                dp[curr][mode] = max(buy_now, buy_later);
            }

            //if we have to sell
            else{
                //possible profit
                int sell_now, sell_later;

                sell_now = prices[curr] + findProfit(curr+2, 0, prices, dp);
                sell_later = findProfit(curr+1, 1, prices, dp);

                dp[curr][mode] = max(sell_now, sell_later);
            }
        }
        return dp[curr][mode];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));

        return findProfit(0, 0, prices, dp);
    }
};
