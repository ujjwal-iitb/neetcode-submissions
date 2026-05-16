class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size()>1){
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            int res = max(a, b) - min(a,b);

            if(res>0){
                pq.push(res);
            }
        }

        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};
