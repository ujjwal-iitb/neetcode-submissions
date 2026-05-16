class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = nums[0];
        int maxN = nums[0];

        int ans = nums[0];

        for(int i = 1; i<n; i++){
            ans = max(ans, nums[i]);
            if(nums[i]==0){
                maxP = 1, maxN = 1;
                continue;
            }
            if(nums[i]<0){
                if(maxN<0){
                    int a = maxP;
                    maxP = maxN*nums[i];
                    maxN = min(nums[i]*a, nums[i]);
                    ans = max(ans, maxP);
                }
                else{
                    maxN = maxP*nums[i];
                    maxP = 1;
                }
            }
            else{
                maxP = maxP * nums[i];
                maxN = maxN * nums[i];

                ans = max(ans, maxP);
            }
        }

        return ans;
    }
};
