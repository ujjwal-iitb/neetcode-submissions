class Solution {
public:
    void getUniqueSubs(vector<int>& nums, vector<int>& p, int curr, vector<vector<int>>& ans){
        if(curr == nums.size()){
            ans.push_back(p);
            return;
        }

        p.push_back(nums[curr]);
        getUniqueSubs(nums, p, curr+1, ans);
        p.pop_back();

        if(p.size()>0 && p[p.size()-1] == nums[curr]){
            return;
        }
        else{
            getUniqueSubs(nums, p, curr+1, ans);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> p;
        getUniqueSubs(nums, p, 0, ans);
        return ans;
    }
};
