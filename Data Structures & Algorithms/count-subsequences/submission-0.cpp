class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if(n<m){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            
            if(s[i]==t[0]){
                dp[i][0] += 1;
            }

            if(i>0){
                dp[i][0] += dp[i-1][0];
            }
        }

        for(int i = 1; i<n; i++){
            for(int j = 1; j<=i && j<m; j++){
                int c_1 = 0, c_2 = 0;
                if(s[i]==t[j]){
                    c_1 = dp[i-1][j-1];
                }
                c_2 = dp[i-1][j];
                dp[i][j] = c_1 + c_2;
            }
        }

        return dp[n-1][m-1];
    }
};
