class Solution {
public:
    vector<int> xm = {1, -1, 0, 0};
    vector<int> ym = {0, 0, 1, -1};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0; //maxSize
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(visited[i][j]!=0 || grid[i][j]==0){
                    continue;
                }
                int size = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    int u = p.first, v = p.second;
                    size++;
                    for(int t = 0; t<4; t++){
                        int x = u + xm[t], y = v + ym[t];

                        if(x>=0 && y>=0 && x<n && y<m && visited[x][y]==0 && grid[x][y]==1){
                            q.push({x, y});
                            visited[x][y] = 1;
                        }
                    }
                    
                }
                ans = max(ans, size);
            }
        }
        return ans;
    }
};
