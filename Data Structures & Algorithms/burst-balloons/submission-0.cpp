class Solution {
public:
    int get(int i, vector<int>& nums){
        if(i==-1 || i==nums.size()){
            return 1;
        }
        else return nums[i];
    }

    int find(int start, int end, vector<int>& nums, unordered_map<int, unordered_map<int, int>>& dp){
        if(end == start + 1){
            return 0;
        }
        if(dp[start].find(end)==dp[start].end()){
            for(int i = start+1; i<end; i++){
                dp[start][end] = max(dp[start][end], find(start, i, nums, dp) + find(i, end, nums, dp) + get(start, nums)*get(i, nums)*get(end, nums));
            }
        }
        return dp[start][end];
    }

    int maxCoins(vector<int>& nums) {
        int start = -1, end = nums.size();
        unordered_map<int, unordered_map<int, int>>dp;
        return find(start, end, nums, dp);
    }
};
