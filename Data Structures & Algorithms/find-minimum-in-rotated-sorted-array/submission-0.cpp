class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int inflectionIndex = 0;
        while(start<=end){
            int mid = (end + start)/2;
            if(nums[mid]>=nums[0]){
                start = mid+1;
            }
            else{
                inflectionIndex = mid;
                end = mid-1;
            }
        }
        return nums[inflectionIndex];
    }
};
