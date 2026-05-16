class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp; 
        for(char c: tasks){
            mp[c]++;
        }

        priority_queue<int> pq;
        for(auto i: mp){
            pq.push(i.second);
        }
        int ans = 0;
        while(!pq.empty()){
            int cycle = 0;
            vector<int> leftTaskCounts;
            while(cycle<=n){
                if(!pq.empty()){
                    int taskCount = pq.top();
                    pq.pop();
                    taskCount--;
                    if(taskCount>0){
                        leftTaskCounts.push_back(taskCount);
                    }
                }
                cycle++;
                ans++;
                if(pq.empty() && leftTaskCounts.size()==0){
                    break;
                }
            }

            for(int i : leftTaskCounts){
                pq.push(i);
            }
        }
        return ans;
    }
};
