class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp (n, vector<int> (n, 0));

        int ans = 1, start = 0, end = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int k = j - i;
                if(k==j){
                    dp[k][j] = 1;
                    continue;
                }
                if(s[k]==s[j]){
                    if(k+1 <= j-1){
                        if(dp[k+1][j-1]>0)
                        {dp[k][j] = 2 + dp[k+1][j-1];}
                        else{
                            dp[k][j] = 0;
                        }
                    }
                    else{
                        dp[k][j] = 2;
                    }
                }
                else{
                    dp[k][j] = 0;
                }
                if(ans <= dp[k][j]){
                    ans = dp[k][j];
                    start = k, end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
