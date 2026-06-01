class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //node degree map -> represents the number of nodes before this node
        unordered_map<int, int> mp;

        vector<vector<int>> graph(numCourses, vector<int>());

        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];

            //we have an edge from v -> u
            graph[v].push_back(u);
            mp[u]++;
        }

        queue<int> q; 

        for(int i = 0; i<numCourses; i++){
            if(mp[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for(int i = 0; i<graph[curr].size(); i++){
                int v = graph[curr][i];
                mp[v]--;
                if(mp[v]==0){
                    q.push(v);
                }
            }
        }

        if(ans.size()==numCourses) return ans;
        else{
            return vector<int>();
        }
    }
};
