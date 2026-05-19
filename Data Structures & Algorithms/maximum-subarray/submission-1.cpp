class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], n = nums.size();
        //vector<int> dp(n, 0);
        //dp[0] = nums[0];

        //for(int i = 1; i<n; i++){
        //    dp[i] = max(nums[i], dp[i-1] + nums[i]);
        //    ans = max(ans, dp[i]);
        //}

        int a = nums[0];
        int b;
        for(int i = 1; i<n; i++){
            b = max(nums[i], a + nums[i]);
            ans = max(ans, b);
            a = b;
        }

        return ans;
    }
};
