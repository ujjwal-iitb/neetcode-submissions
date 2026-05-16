class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        vector<int> dp (n, 0);

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        for(int i = n-1; i>=0; i--){
            bool flag = false;
            for(int j = n-1; j>=i; j--){
                if(st.find(s.substr(i, j-i + 1))!= st.end()){
                    if((j+1<n && dp[j+1]) || j+1 >= n){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag){
                dp[i] = 1;
            }
        }

        return dp[0];
    }
};
