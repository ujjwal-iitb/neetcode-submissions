class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
        int n = pq.size();

        unordered_map<int, unordered_map<int, int>> visited;

        pair<int, int> start = {points[0][0], points[0][1]};

        pq.push({-1, start});

        int ans = 0;

        while(!pq.empty()){
            int wt = pq.top().first; 
            pair<int, int> node = pq.top().second;
            pq.pop();

            if(visited[node.first][node.second]==0){      //not yet visited
                wt>=0?ans+=wt:ans;
                visited[node.first][node.second] = 1;

                for(auto p: points){
                    if(visited[p[0]][p[1]]==0){
                        int currWt = abs(node.first - p[0]) + abs(node.second - p[1]);
                        pq.push({currWt, {p[0], p[1]}});
                    }
                }
            }
        }
        
        return ans;
    }
};
