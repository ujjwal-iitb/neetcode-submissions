class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0; 

        int n = prices.size();

        vector<int> rightMax(n, 0);

        rightMax[n-1] = prices[n-1];

        for(int i = n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], prices[i]);

            ans = max(ans, rightMax[i] - prices[i]);
        }

        return ans;
    }
};
