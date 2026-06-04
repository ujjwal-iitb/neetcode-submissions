class Solution {
public:

    void dfs(string curr, unordered_map<string, vector<string>>& graph, unordered_map<string, int>& outDegree, vector<string>& ans){
        while(outDegree[curr]>0){
            int i = outDegree[curr] - 1;

            outDegree[curr]--;

            string newNode = graph[curr][i];

            dfs(newNode, graph, outDegree, ans);
        }
        ans.push_back(curr);
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;

        unordered_map<string, int> inDegree, outDegree;

        //unordered_set<string> nodes;

        for(auto edge: tickets){
            string u = edge[0], v = edge[1];

            graph[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;

            //nodes.add(u);
            //nodes.add(v);
        }

        for(auto& nodeEdges: graph){
            string node = nodeEdges.first;
            sort(nodeEdges.second.begin(), nodeEdges.second.end());
            reverse(nodeEdges.second.begin(), nodeEdges.second.end());
        }

        vector<string> ans;

        string start = "JFK";

        dfs(start, graph, outDegree, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
