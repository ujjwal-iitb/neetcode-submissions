class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] leftProduct = new int[n];
        int[] rightProduct = new int[n];

        for(int i = 0; i<n; i++){
            if(i==0){
                leftProduct[0] = nums[i];
                rightProduct[n-1] = nums[n-1];
            }
            else{
                leftProduct[i] = nums[i]*leftProduct[i-1];
                rightProduct[n-1-i] = nums[n-1-i]*rightProduct[n-i];
            }
        }

        int[] ans = new int[n];

        for(int i = 0; i<n; i++){
            if(i==0){
                ans[i] = rightProduct[1];
            }
            else if(i==n-1){
                ans[i] = leftProduct[i-1];
            }
            else{
                ans[i] = leftProduct[i-1]*rightProduct[i+1];
            }
        }

        return ans;
    }
}  
