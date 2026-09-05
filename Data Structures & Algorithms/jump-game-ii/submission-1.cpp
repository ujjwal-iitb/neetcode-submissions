class Solution {
public:
    int jump(vector<int>& nums) {
        queue<int> q;

        q.push(nums[0]);

        int count = 1, start = 0, end = 0, maxReach = 0, n = nums.size();

        if(n==1){
            return 0;
        }

        while(start<=end){
            maxReach = max(maxReach, nums[start] + start);
            if(maxReach >= n-1){
                return count;
            }

            if(start == end){
                start = end + 1;
                end = maxReach;
                count++;
            }
            else{
                start++;
            }
        }

        return -1;
    }
};
