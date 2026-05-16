class Solution {
public:
    void getCombinationSum(vector<int>& nums, int target, int curr, int currSum, vector<int>& v, vector<vector<int>>& ans){
        if(currSum>target || curr>=nums.size()){
            return;
        }

        if(currSum==target){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[curr]);
        currSum+=nums[curr];

        getCombinationSum(nums, target, curr, currSum, v, ans);

        v.pop_back();

        currSum-=nums[curr];

        getCombinationSum(nums, target, curr+1, currSum, v, ans);
        
        return;

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> v; 

        getCombinationSum(nums, target, 0, 0, v, ans);
        return ans;
    }
};
