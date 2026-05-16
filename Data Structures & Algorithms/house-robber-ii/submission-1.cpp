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
            return max(nums[0], max(nums[1], nums[2]));
        }
        int a = nums[0], b = nums[1], c = a + nums[2], d = a + nums[2];

        for(int i = 3; i<nums.size() - 1; i++){
            d = nums[i] + max(a, b);
            a = b;
            b = c; 
            c = d;
        }
        int ans1 = max(d, b);
        if(n<=3){
            return ans1;
        }
        
        a = nums[1], b = nums[2], c = a + nums[3], d = a + nums[3];

        for(int i = 4; i<nums.size(); i++){
            d = nums[i] + max(a, b);
            a = b;
            b = c; 
            c = d;
        }

        int ans2 = max(d, b);

        return max(ans1, ans2);

    }
};
