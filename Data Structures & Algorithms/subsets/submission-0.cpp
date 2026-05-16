class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, int curr){
        if(curr == nums.size()){
            ans.push_back(v);
            return;
        }
        
        getSubsets(nums, v, ans, curr+1);
        v.push_back(nums[curr]);
        getSubsets(nums, v, ans, curr+1);
        v.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        getSubsets(nums, v, ans, 0);
        return ans;
    }
};
