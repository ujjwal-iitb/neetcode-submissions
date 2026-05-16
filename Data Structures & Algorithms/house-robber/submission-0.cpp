class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        if(n==3){
            return max(nums[0]+nums[2], nums[1]);
        }
        int a = nums[0], b = nums[1], c = a + nums[2], d;

        for(int i = 3; i<nums.size(); i++){
            d = nums[i] + max(a, b);
            a = b;
            b = c; 
            c = d;
        }

        return max(d, b);
    }
};
