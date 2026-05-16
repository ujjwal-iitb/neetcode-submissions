class Solution {
public:

    int findMinNumber(int amt, vector<int>& coins, unordered_map<int, int>& dp){
        if(amt==0){
            return 0;
        }
        if(dp.find(amt)==dp.end()){
            int ans = INT_MAX;
            bool flag = false;
            for(int i = 0; i<coins.size(); i++){
                if(coins[i]<=amt && findMinNumber(amt - coins[i], coins, dp) >= 0){
                    ans = min(ans, 1 + findMinNumber(amt - coins[i], coins, dp));
                    flag = true;
                }
            }
            if(flag){
                dp[amt] = ans;
            }
            else{
                dp[amt] = -1;
            }
        }
        return dp[amt];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }

        unordered_map<int, int> dp; 
        int ans = INT_MAX;

        return findMinNumber(amount, coins, dp);
    }
};
