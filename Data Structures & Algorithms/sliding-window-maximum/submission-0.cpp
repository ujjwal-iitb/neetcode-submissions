class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int start = 0, end = k-1, n = nums.size();

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<k-1; i++){
            pq.push({nums[i], i});
        }

        vector<int> ans;

        while(end<n){
            pq.push({nums[end], end});
            while(true){
                pair<int, int> p = pq.top();
                if(p.second >= start && p.second <= end){
                    ans.push_back(p.first);
                    break;
                }
                else{
                    pq.pop();
                }
            }

            end++;
            start++;
        }

        return ans;
    }
};
