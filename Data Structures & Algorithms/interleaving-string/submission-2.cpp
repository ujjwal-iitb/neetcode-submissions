class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        if(m + n != s3.length()){
            return 0;
        }
        if(m==n && n==0){
            return 1;
        }
        if(n>0 && s1[0]==s3[0]){
            dp[1][0] = 1;
        }
        if(m>0 && s2[0]==s3[0]){
            dp[0][1] = 1;
        }


        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i==0 && j==0) continue;

                //check s1
                if(i>0 && s1[i-1]==s3[i+j-1]){
                    dp[i][j] += dp[i-1][j];
                }

                //check s2
                if(j>0 && s2[j-1] == s3[i + j -1]){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[n][m]>0;
    }
};
