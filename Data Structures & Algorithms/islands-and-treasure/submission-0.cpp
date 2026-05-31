class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q; 

        vector<int> xm = {1, 0, -1, 0}, ym = {0, 1, 0, -1};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({i, j});
                }
            }
        }

        //vector<vector<int>> visited(n, vector<int> (m, 0));
        int step = 0;
        while(!q.empty()){
            step++;
            int size = q.size();
            for(int t = 0; t<size; t++){
                pair<int, int> p = q.front();
                q.pop();

                for(int u = 0; u<4; u++){
                    int x = p.first + xm[u];
                    int y = p.second + ym[u];

                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==INT_MAX){
                        grid[x][y] = step;
                        q.push({x, y});
                    }
                }

            }
        }
    }
};
