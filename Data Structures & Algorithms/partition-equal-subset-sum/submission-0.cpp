class Solution {
public:
    bool cp(int diff, int index, vector<int>& nums, unordered_map<int, unordered_map<int, int>>& dp){
        if(index==nums.size()){
            return diff==0;
        }

        if(dp[diff].find(index)==dp[diff].end()){
            int new_diff_a = diff - nums[index];
            int new_diff_b = diff + nums[index];

            dp[diff][index] = cp(new_diff_a, index + 1, nums, dp) || cp(new_diff_b, index + 1, nums, dp);
        }
        return dp[diff][index];
    }

    bool canPartition(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> dp; //{diff, index}--> 0, 1

        return cp(0, 0, nums, dp);
    }
};
