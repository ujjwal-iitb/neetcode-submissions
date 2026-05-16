class Solution {
public: 
    void getAllPermutations(vector<int>& nums, vector<int>& visited, vector<int>& p, vector<vector<int>>& ans){
        if(p.size() == nums.size()){
            ans.push_back(p);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(visited[i]==0){
                p.push_back(nums[i]);
                visited[i] = 1;
                getAllPermutations(nums, visited, p, ans);
                p.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> visited(n, 0);
        vector<int> p;
        getAllPermutations(nums, visited, p, ans);
        return ans;
    }
};
