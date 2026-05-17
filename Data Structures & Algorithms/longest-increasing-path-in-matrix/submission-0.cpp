class Solution {
public:
    vector<int> xm = {1, -1, 0, 0};
    vector<int> ym = {0, 0, 1, -1};

    bool isValid(int i, int j, vector<vector<int>>& matrix){
        if(i<=-1 || j<=-1 || i>=matrix.size() || j>=matrix[0].size()){
            return false;
        }
        return true;
    }

    int find(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(dp[i][j]==-1){
            dp[i][j] = 1;
            for(int t = 0; t<4; t++){
                int x = i + xm[t], y = j + ym[t];
                if(isValid(x, y, matrix) && matrix[i][j]<matrix[x][y]){
                    dp[i][j] = max(dp[i][j], 1 + find(x, y, matrix, dp));
                }
            }
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 1;

        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = max(ans, find(i, j, matrix, dp));
            }
        }

        return ans;
    }
};
