class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = nums[i];
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == -target) {
                    ans.push_back({target, nums[left], nums[right]});

                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);

                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right + 1]);
                }
                else if (sum > -target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};
